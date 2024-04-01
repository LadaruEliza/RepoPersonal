#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstring>
#include <ctime>
#include <stdio.h>
using namespace sf;
using namespace std;
void temporizator(){
    int cat_ramane,oo,mm,ss;
    char sir_ora[3],sir_min[3],sir_sec[3];
    SoundBuffer sunet;
    Sound alarma;
    sunet.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\classic.wav");
    alarma.setBuffer(sunet);
    alarma.setLoop(true);
    int timpx=-1,timpy=0;
    bool doar_o_data=false;
    int ora_cur,min_cur,sec_cur,ora_fin,min_fin,sec_fin;
    char csec[3],cmin[3],cora[3];
    RenderWindow window(VideoMode(1920,1080),"Temporizator",Style::Fullscreen);
    Font font;
    font.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\lato\\Lato-BoldItalic.ttf");
    Sprite sprite;
    Texture texture;
    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\temp.jpg");
    sprite.setTexture(texture);

    CircleShape start(50),anulati(50),cover_start(40),cover_anulati(40);
    start.setFillColor(Color::Green);
    anulati.setFillColor(Color(105,105,105));
    start.setPosition(600,540);
    anulati.setPosition(300,540);
    cover_anulati.setFillColor(Color(105,105,105)); cover_anulati.setOutlineColor(Color::Black); cover_anulati.setOutlineThickness(2.0f);
    cover_start.setFillColor(Color::Green); cover_start.setOutlineColor(Color::Black); cover_start.setOutlineThickness(2.0f);
    cover_anulati.setPosition(310,550);
    cover_start.setPosition(610,550);

    Text tstart,tstop;
    tstart.setCharacterSize(30); tstart.setFont(font); tstart.setString("Start"); tstart.setColor(Color(0,100,0));
    tstop.setCharacterSize(30); tstop.setFont(font); tstop.setString("Stop"); tstop.setColor(Color::Black);
    tstart.setPosition(617,570);
    tstop.setPosition(320,570);

    RectangleShape dreptunghi;
    dreptunghi.setSize(Vector2f(480,200));
    dreptunghi.setFillColor(Color::Black);
    dreptunghi.setOutlineThickness(2.0f);
    dreptunghi.setOutlineColor(Color::White);
    dreptunghi.setPosition(275,300);

    Text tore,tmin,tsec;
    tore.setFont(font); tore.setCharacterSize(30); tore.setString("ore"); tore.setColor(Color::White);
    tmin.setFont(font); tmin.setCharacterSize(30); tmin.setString("min."); tmin.setColor(Color::White);
    tsec.setFont(font); tsec.setCharacterSize(30); tsec.setString("sec."); tsec.setColor(Color::White);
    int y=380;
    tore.setPosition(370,y);
    tmin.setPosition(515,y);
    tsec.setPosition(665,y);

    int ora=0,min=0,sec=0;
    Text to,tmx,ts;
    to.setFont(font); to.setCharacterSize(30); to.setString("0"); to.setColor(Color::White);
    tmx.setFont(font); tmx.setCharacterSize(30); tmx.setString("0"); tmx.setColor(Color::White);
    ts.setFont(font); ts.setCharacterSize(30); ts.setString("0"); ts.setColor(Color::White);
    to.setPosition(330,y);
    tmx.setPosition(475,y);
    ts.setPosition(625,y);

    Text plus[3],minus[3];
    for(int i=0;i<3;i++){
        plus[i].setFont(font);
        minus[i].setFont(font);
        plus[i].setCharacterSize(40);
        minus[i].setCharacterSize(55);
        plus[i].setColor(Color::Cyan);
        minus[i].setColor(Color::Cyan);
        plus[i].setString("+");
        minus[i].setString("-");
        minus[i].setPosition(i*200+330,320);
        plus[i].setPosition(i*200+320,420);
    }
    minus[0].setPosition(330,320); minus[1].setPosition(475,320); minus[2].setPosition(625,320);
    plus[0].setPosition(325,420); plus[1].setPosition(470,420); plus[2].setPosition(620,420);

    Text verificare;
    verificare.setFont(font);
    verificare.setCharacterSize(50);
    verificare.setColor(Color::Transparent);
    verificare.setString("MERGE BA");
    verificare.setPosition(800,600);
    bool suna=false;
    bool start_apasat=false,stop_apasat=false;
    CircleShape cerc_alarma(200);
    cerc_alarma.setFillColor(Color::Transparent);
    cerc_alarma.setPosition(300,150);

    Text suna_alarma;
    suna_alarma.setFont(font); suna_alarma.setCharacterSize(35); suna_alarma.setColor(Color::Transparent);
    suna_alarma.setString("Timpul a expirat!"); suna_alarma.setPosition(380,210);

    Text ora_alarma,min_alarma,sec_alarma;
    ora_alarma.setFont(font); ora_alarma.setCharacterSize(50); ora_alarma.setColor(Color::Transparent);
    min_alarma.setFont(font); min_alarma.setCharacterSize(50); min_alarma.setColor(Color::Transparent);
    sec_alarma.setFont(font); sec_alarma.setCharacterSize(50); sec_alarma.setColor(Color::Transparent);
    //ora_alarma.setString("00"); min_alarma.setString("12"); sec_alarma.setString("06");
    ora_alarma.setPosition(390,330); min_alarma.setPosition(470,330); sec_alarma.setPosition(550,330);

    Text punct[2];
    for(int i=0;i<2;i++){
        punct[i].setFont(font);
        punct[i].setCharacterSize(50);
        punct[i].setColor(Color::Transparent);
        punct[i].setString(":");
    }
    punct[0].setPosition(455,330);
    punct[1].setPosition(530,330);
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed) window.close();
            if(event.type==Event::KeyPressed)
                if(Keyboard::isKeyPressed(Keyboard::Escape)) window.close();

            if(Mouse::getPosition().x>=330&&Mouse::getPosition().x<=350&&Mouse::getPosition().y>=355&&Mouse::getPosition().y<=365){
                minus[0].setColor(Color::Red);
                if(event.type==Event::MouseButtonPressed){
                    if(ora>0) ora--;
                    else ora=23;
                }
            }
            else minus[0].setColor(Color::Cyan);

            if(Mouse::getPosition().x>=475&&Mouse::getPosition().x<=495&&Mouse::getPosition().y>=355&&Mouse::getPosition().y<=365){
                minus[1].setColor(Color::Red);
                if(event.type==Event::MouseButtonPressed){
                    if(min>0) min--;
                    else min=59;
                }
            }
            else minus[1].setColor(Color::Cyan);

            if(Mouse::getPosition().x>=625&&Mouse::getPosition().x<=645&&Mouse::getPosition().y>=355&&Mouse::getPosition().y<=365){
                minus[2].setColor(Color::Red);
                if(event.type==Event::MouseButtonPressed){
                    if(sec>0) sec--;
                    else sec=59;
                }
            }
            else minus[2].setColor(Color::Cyan);

            if(Mouse::getPosition().x>=325&&Mouse::getPosition().x<=350&&Mouse::getPosition().y>=440&&Mouse::getPosition().y<=460){
                plus[0].setColor(Color::Red);
                if(event.type==Event::MouseButtonPressed){
                    if(ora<23) ora++;
                    else ora=0;
                }
            }
            else plus[0].setColor(Color::Cyan);

            if(Mouse::getPosition().x>=470&&Mouse::getPosition().x<=495&&Mouse::getPosition().y>=440&&Mouse::getPosition().y<=460){
                plus[1].setColor(Color::Red);
                if(event.type==Event::MouseButtonPressed){
                    if(min<59) min++;
                    else min=0;
                }
            }
            else plus[1].setColor(Color::Cyan);

            if(Mouse::getPosition().x>=620&&Mouse::getPosition().x<=645&&Mouse::getPosition().y>=440&&Mouse::getPosition().y<=460){
                plus[2].setColor(Color::Red);
                if(event.type==Event::MouseButtonPressed){
                    if(sec<59) sec++;
                    else sec=0;
                }
            }
            else plus[2].setColor(Color::Cyan);

            if(Mouse::getPosition().x>=600&&Mouse::getPosition().x<=700&&Mouse::getPosition().y>=570&&Mouse::getPosition().y<=650){
                cover_start.setFillColor(Color::White);
                if(event.type==Event::MouseButtonPressed)
                    start_apasat=true;
                    stop_apasat=false;
            }
            else cover_start.setFillColor(Color::Green);

            if(Mouse::getPosition().x>=300&&Mouse::getPosition().x<=400&&Mouse::getPosition().y>=570&&Mouse::getPosition().y<=650){
                cover_anulati.setFillColor(Color::White);
                if(event.type==Event::MouseButtonPressed){
                    stop_apasat=true;
                    start_apasat=false;
                }
            }
            else cover_anulati.setFillColor(Color(105,105,105));
        }
        if(start_apasat){
            cerc_alarma.setFillColor(Color::Black);
            dreptunghi.setFillColor(Color::Transparent);
            dreptunghi.setOutlineColor(Color::Transparent);
            for(int i=0;i<3;i++){
                plus[i].setColor(Color::Transparent);
                minus[i].setColor(Color::Transparent);
            }
            tore.setColor(Color::Transparent); tmin.setColor(Color::Transparent); tsec.setColor(Color::Transparent);
            to.setColor(Color::Transparent); tmx.setColor(Color::Transparent); ts.setColor(Color::Transparent);

            int secunde=ora*3600+min*60+sec;
            time_t timp_curent;
            timp_curent=time(NULL);
            tm* timp_local=localtime(&timp_curent);
            if(doar_o_data==false){
                ora_cur=timp_local->tm_hour;
                min_cur=timp_local->tm_min;
                sec_cur=timp_local->tm_sec;
                doar_o_data=true;
            }
            timpx=secunde+ora_cur*3600+min_cur*60+sec_cur;
            timpy=timp_local->tm_hour*3600+timp_local->tm_min*60+timp_local->tm_sec;
            if(timpx==timpy&&suna==false){
                alarma.play();
                suna=true;
                suna_alarma.setColor(Color::White);
            }
            cat_ramane=timpx-timpy;
            oo=cat_ramane/3600;
            mm=(cat_ramane%3600)/60;
            ss=(cat_ramane%3600)%60;
            sprintf(sir_ora,"%d",oo);
            sprintf(sir_min,"%d",mm);
            sprintf(sir_sec,"%d",ss);
            if(strlen(sir_ora)==1){
                char aux=sir_ora[0];
                sir_ora[0]='0';
                sir_ora[1]=aux;
                sir_ora[2]=NULL;
            }
            if(strlen(sir_min)==1){
                char aux=sir_min[0];
                sir_min[0]='0';
                sir_min[1]=aux;
                sir_min[2]=NULL;
            }
            if(strlen(sir_sec)==1){
                char aux=sir_sec[0];
                sir_sec[0]='0';
                sir_sec[1]=aux;
                sir_sec[2]=NULL;
            }
            ora_alarma.setString(sir_ora);
            min_alarma.setString(sir_min);
            sec_alarma.setString(sir_sec);
            if(cat_ramane<=0){
                ora_alarma.setString("00");
                min_alarma.setString("00");
                sec_alarma.setString("00");
            }
            ora_alarma.setColor(Color::White);
            min_alarma.setColor(Color::White);
            sec_alarma.setColor(Color::White);
            punct[0].setColor(Color::White); punct[1].setColor(Color::White);
        }
        if(stop_apasat){
            punct[0].setColor(Color::Transparent); punct[1].setColor(Color::Transparent);
            ora_alarma.setColor(Color::Transparent);
            min_alarma.setColor(Color::Transparent);
            sec_alarma.setColor(Color::Transparent);
            suna_alarma.setColor(Color::Transparent);
            cerc_alarma.setFillColor(Color::Transparent);
            alarma.stop();
            suna=false;
            doar_o_data=false;
            verificare.setColor(Color::Transparent);
            dreptunghi.setFillColor(Color::Black);
            dreptunghi.setOutlineColor(Color::White);
            for(int i=0;i<3;i++){
                plus[i].setColor(Color::Cyan);
                minus[i].setColor(Color::Cyan);
            }
            tore.setColor(Color::White); tmin.setColor(Color::White); tsec.setColor(Color::White);
            to.setColor(Color::White); tmx.setColor(Color::White); ts.setColor(Color::White);
        }
        sprintf(csec,"%d",sec);
        sprintf(cmin,"%d",min);
        sprintf(cora,"%d",ora);
        to.setString(cora); tmx.setString(cmin); ts.setString(csec);
        window.draw(sprite);
        window.draw(start); window.draw(anulati);
        window.draw(cover_start); window.draw(cover_anulati);
        window.draw(tstart); window.draw(tstop);
        window.draw(dreptunghi);
        window.draw(tore); window.draw(tmin); window.draw(tsec);
        window.draw(to); window.draw(tmx); window.draw(ts);
        window.draw(verificare);
        for(int i=0;i<3;i++){
            window.draw(plus[i]); window.draw(minus[i]);
        }
        window.draw(cerc_alarma);
        window.draw(suna_alarma);
        window.draw(sec_alarma); window.draw(min_alarma); window.draw(ora_alarma); window.draw(punct[0]); window.draw(punct[1]);
        window.display();

    }
}
