#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

#define FILENAME "questions.xml"
#define PORT 2936

extern int errno;

int port;

typedef struct {
    char intrebare[256];
    char raspunsuri[4][256];
    char raspunsCorect;
} Intrebare;

void citesteIntrebare(int sd, Intrebare *intrebare);

int main(int argc, char *argv[]) {
    int sd;
    struct sockaddr_in server;

    if (argc != 3) {
        printf("Sintaxa: %s <adresa_server> <port>\n", argv[0]);
        return -1;
    }

    port = atoi(argv[2]);

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("[client]Eroare la socket().\n");
        return errno;
    }

    server.sin_family = AF_INET;
    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        perror("[client]Eroare la inet_pton().\n");
        return errno;
    }
    server.sin_port = htons(port);

    if (connect(sd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1) {
        perror("[client]Eroare la connect().\n");
        return errno;
    }

    Intrebare intrebari[6];
    char nume[100];
    printf("Introduceti un nume de utilizator: ");
    fflush(stdout);
    scanf("%s", nume);
    write(sd, nume, sizeof(nume));

    for (int i = 0; i < 6; i++) {
        citesteIntrebare(sd, &intrebari[i]);

        printf("Intrebarea %d: %s\n", i + 1, intrebari[i].intrebare);
        for (int j = 1; j <= 3; j++) {
            printf("Varianta %c: %s\n", 'A' + j - 1, intrebari[i].raspunsuri[j]);
        }

        char raspuns[2];
        printf("Raspunsul tau (A/B/C): ");
        fflush(stdout);
        scanf(" %c", raspuns);
        write(sd, raspuns, sizeof(raspuns));
        sleep(1);
    }
    char mesaj_castigator[256];
    if (read(sd, mesaj_castigator, sizeof(mesaj_castigator)) < 0) {
        perror("[client] Eroare la citirea mesajului castigatorului");
    } else {
        printf("%s\n", mesaj_castigator); 
    }

    close(sd);
}

void citesteIntrebare(int sd, Intrebare *intrebare) {
    read(sd, intrebare->intrebare, sizeof(intrebare->intrebare));
    sleep(1);

    for (int i = 0; i < 4; i++) {
        read(sd, intrebare->raspunsuri[i], sizeof(intrebare->raspunsuri[i]));
        sleep(1);
    }
}
