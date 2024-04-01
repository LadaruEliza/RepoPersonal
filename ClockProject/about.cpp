#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>
using namespace std;
using namespace sf;
void sectiuneDespre(){
    char linie1[]=" Proiectul acesta a fost realizat de Boita Razvan-Mihai si Ladaru Eliza, din grupa AI, cu profesorul indrumator Patrut Bogdan. Proiectul are ca scop crearea";
    char linie2[]=" unui ceas digital si a unui ceas analogic. Pentru dezvoltarea proiectului a fost folosit limbajul C++, iar pentru partea grafica a fost folosita biblioteca";
    char linie3[]=" SFML. Aplicatia prezinta la start un meniu simplu, cu diverse optiuni pe care user-ul le poate alege prin apasarea butoanelor corespunzatoare, precum:     ";
    char linie4[]=" Ceasul Analogic, Ceasul Digital, Setarea unei alarme sau vizualizarea sectiunii informative a proiectului. Fiecare functie are diferite caracteristici,";
    char linie5[]=" precum setarea TimeZone-ului( in cazul ceasului digital ) , preview-ul sunetului unei alarme sau setarea manuala a alarmei ( in cazul alarmei ).";
    RenderWindow meniu2(VideoMode(1920,1080),"Despre proiectul nostru",Style::Fullscreen);
    Sprite sprited;
    Font font;
    Texture texture;
    Text linii[5];
    font.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\lato\\Lato-LightItalic.ttf");
    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\blackpic.jpg");
    sprited.setTexture(texture);
    for(int i=0;i<5;i++){
        linii[i].setFont(font);
        linii[i].setCharacterSize(30);
        linii[i].setColor(Color::White);
        linii[i].setPosition(16,50*i+20);
    }
    linii[0].setString(linie1);
    linii[1].setString(linie2);
    linii[2].setString(linie3);
    linii[3].setString(linie4);
    linii[4].setString(linie5);
    while(meniu2.isOpen()){
        Event event;
        while(meniu2.pollEvent(event)){
            if(event.type==Event::Closed) meniu2.close();

            if(event.type==Event::KeyPressed){
                if(Keyboard::isKeyPressed(Keyboard::Escape))
                   meniu2.close();
        }
    }
    meniu2.draw(sprited);
    for(int i=0;i<5;i++) meniu2.draw(linii[i]);
    meniu2.display();
}
}
