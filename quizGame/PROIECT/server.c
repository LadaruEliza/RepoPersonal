#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <ctype.h>

#define FILENAME "questions.xml"
#define PORT 2971

extern int errno;

static void *handler(void *);
typedef struct {
    char intrebare[256];
    char raspunsuri[4][256];
    char raspunsCorect;
} Intrebare;

typedef struct {
    char username[100];
    int punctaj;
    int client_socket;
} Client;

Intrebare *intrebari;
pthread_mutex_t mlock = PTHREAD_MUTEX_INITIALIZER;
Client *clients = NULL;
int num_clients=0;
void trimitereClient(int cl, Client *instClient);
void citireXML(const char *fisier);
void asteapta(int client, int secunde, Client *instClient, int indexIntrebare);

int main() {
    struct sockaddr_in server;
    int sd;

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("[server]Eroare la socket().\n");
        return errno;
    }

    int on = 1;
    setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);

    if (bind(sd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1) {
        perror("[server]Eroare la bind().\n");
        return errno;
    }

    if (listen(sd, 5) == -1) {
        perror("[server]Eroare la listen().\n");
        return errno;
    }

    citireXML(FILENAME);

    for (;;) {
        printf("[server]Asteptam la portul %d...\n", PORT);
        int client;
        struct sockaddr_in from;
        bzero(&from, sizeof(from));
        int length = sizeof(from);

        if ((client = accept(sd, (struct sockaddr *)&from, &length)) < 0) {
            perror("[server]Eroare la accept().\n");
            continue;
        }

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, &handler, (void *)(intptr_t)client) != 0) {
            perror("[server]Eroare la pthread_create().\n");
            continue;
        }
        pthread_detach(thread_id);
    }
    free(clients);
}

void *handler(void *arg) {
    int client = (intptr_t)arg;
    printf("[thread]- %d - pornit...\n", client);
    fflush(stdout);
    Client instClient;
    instClient.punctaj = 0;
    char nume[100];
    if (read(client, nume, sizeof(nume)) < 0) {
        perror("[thread] - Eroare la citirea numelui clientului");
        close(client);
        return NULL;
    }
    strncpy(instClient.username, nume, sizeof(instClient.username) - 1);

    trimitereClient(client, &instClient);
    close(client);
   pthread_mutex_lock(&mlock);
   num_clients++;
    clients = (Client *)realloc(clients, num_clients * sizeof(Client));
    clients[num_clients - 1] = instClient;
    pthread_mutex_unlock(&mlock);
    return NULL;
}

void trimitereClient(int cl, Client *instClient) {
    for (int i = 0; i < 6; i++) {
        write(cl, intrebari[i].intrebare, sizeof(intrebari[i].intrebare));
        sleep(1);

        for (int j = 0; j < 4; j++) {
            write(cl, intrebari[i].raspunsuri[j], sizeof(intrebari[i].raspunsuri[j]));
            sleep(1);
        }
        asteapta(cl, 15, instClient, i);
    } char mesaj_castigator[256];
    snprintf(mesaj_castigator, sizeof(mesaj_castigator), "Felicitari, %s!  Ai obtinut %d puncte. Jocul s-a incheiat.",instClient->username, instClient->punctaj);
    write(cl, mesaj_castigator, sizeof(mesaj_castigator));
}

void citireXML(const char *fisier) {
     FILE *file = fopen(fisier, "r");
    if (!file) {
        fprintf(stderr, "Eroare la deschiderea fișierului XML.\n");
        return;
    }

    char buffer[1024];
    char *start, *end;
    int numarIntr = 0;

    intrebari = (Intrebare *)malloc(6 * sizeof(Intrebare));

    while (fgets(buffer, sizeof(buffer), file)) {
        if ((start = strstr(buffer, "<question>")) != NULL) {
            Intrebare intrebare;

            if (fgets(buffer, sizeof(buffer), file) && (start = strchr(buffer, '>')) != NULL) {
                start++;
                if ((end = strstr(start, "</text>")) != NULL) {
                    *end = '\0';
                    snprintf(intrebare.intrebare, sizeof(intrebare.intrebare), "%s", start);
                }
            }
            for (int i = 0; i < 4; i++) {
                if (fgets(buffer, sizeof(buffer), file) && (start = strchr(buffer, '>')) != NULL) {
                    start++;
                    if ((end = strstr(start, "</answer>")) != NULL) {
                        *end = '\0';
                        snprintf(intrebare.raspunsuri[i], sizeof(intrebare.raspunsuri[i]), "%s", start);
                    }
                }
            }
            while (fgets(buffer, sizeof(buffer), file) && strstr(buffer, "<correctAnswer>") == NULL);
            if ((start = strchr(buffer, '>')) != NULL) {
                start++;
                if ((end = strchr(start, '<')) != NULL) {
                    *end = '\0';
                    while (isspace(*start)) start++;
                    intrebare.raspunsCorect = *start;
                }
            }
            intrebari[numarIntr++] = intrebare;
        }
    }
    fclose(file);
}

void asteapta(int client, int secunde, Client *instClient, int indexIntrebare) {
    struct timeval timeout;
    timeout.tv_sec = secunde;
    timeout.tv_usec = 0;

    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(client, &fds);

    int rezultat = select(client + 1, &fds, NULL, NULL, &timeout);

    if (rezultat == 0) {
        instClient->punctaj += 0;
        printf("[thread] - %d - Timpul a expirat. Niciun raspuns.Paraseste jocul.\n", client);
    } else if (rezultat > 0) {
        char raspuns[256];
        read(client, raspuns, sizeof(raspuns));
        printf("[thread] - %d - Raspunsul primit: %s\n", client, raspuns);
        if (raspuns[0] == intrebari[indexIntrebare].raspunsCorect) {
            instClient->punctaj++;
            printf("[thread] - %d - Raspuns corect! Punctaj acumulat: %d\n", client, instClient->punctaj);
        } else {
            instClient->punctaj += 0;
            printf("[thread] - %d - Raspuns gresit! Punctaj acumulat: %d\n", client, instClient->punctaj);
        }
    } else {
        perror("[thread] - Eroare la select");
    }
    printf("[thread] - Intrebare %d - Raspuns corect: %c\n", indexIntrebare + 1, intrebari[indexIntrebare].raspunsCorect);
}
