#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstring>
using namespace sf;
using namespace std;
void ceasAlarma(){
char mal[3],hal[3];
bool op1,op2,op3,op4,stop;
char CLASICA[]="1. Classic Alarm";
char COCOS[]="2. Rooster Alarm";
char SECURITATE[]="3. Security breach Alarm";
char NAVA[]="4. Spaceship Alarm";
    SoundBuffer al1,al2,al3,al4;
    Sound a1,a2,a3,a4;
    al1.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\classic.wav");
    al2.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\rooster.wav");
    al3.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\security.wav");
    al4.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\space.wav");
    a1.setBuffer(al1);
    a2.setBuffer(al2);
    a3.setBuffer(al3);
    a4.setBuffer(al4);
    a1.setLoop(true);
    a2.setLoop(true);
    a3.setLoop(true);
    a4.setLoop(true);

    Text alarmasuna,opreste_alarma;
    opreste_alarma.setCharacterSize(45);
    opreste_alarma.setColor(Color::Red);
    opreste_alarma.setString("");
    opreste_alarma.setPosition(640,200);
    RenderWindow alarma(VideoMode(1920,1080),"Alarma",Style::Fullscreen);
    Texture textura;
    Sprite sprit;
    Font font,fontdig;
    font.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\lato\\Lato-Bold.ttf");
    fontdig.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\digitalnumbers-regular.ttf");
    alarmasuna.setFont(font);
    opreste_alarma.setFont(font);
    RectangleShape drept1,drept2,mici[4];
    RectangleShape optiuni[4];
    RectangleShape startbutton,cancelbutton;
    startbutton.setSize(Vector2f(250,70));
    startbutton.setFillColor(Color::Green);
    startbutton.setPosition(665,600);

    cancelbutton.setSize(Vector2f(250,70));
    cancelbutton.setFillColor(Color::Red);
    cancelbutton.setPosition(665,600);

    Text cancel,start;
    cancel.setColor(Color::White);
    cancel.setFont(font);
    cancel.setCharacterSize(35);
    cancel.setPosition(710,615);
    cancel.setString("ANULEAZA");

    start.setColor(Color::White);
    start.setFont(font);
    start.setCharacterSize(35);
    start.setPosition(720,615);
    start.setString("SETEAZA");

    bool last=1;

    for(int i=0;i<4;i++){
        optiuni[i].setSize(Vector2f(400,50));
        optiuni[i].setFillColor(Color::Green);
        optiuni[i].setPosition(1240,260+i*100);
    }
    drept1.setSize(Vector2f(400,280));
    drept2.setSize(Vector2f(400,280));
    drept1.setPosition(590,300);
    drept2.setPosition(1250,300);
    drept1.setFillColor(Color::Cyan);
    drept2.setFillColor(Color::Black);
    bool prim=false;
    for(int i=0;i<4;i++){
        mici[i].setSize(Vector2f(30,30));
        mici[i].setFillColor(Color::White);
    }
    int x=650;
    mici[0].setPosition(x,500);
    mici[1].setPosition(x+50,500);
    mici[2].setPosition(x+200,500);
    mici[3].setPosition(x+250,500);

    Text wakemeup, sound,plus[2],minus[2],tmina,toraa;
    Text preview[4];
    for(int i=0;i<=3;i++){
        preview[i].setFont(font);
        preview[i].setCharacterSize(25);
        preview[i].setColor(Color::Black);
        preview[i].setString("<<preview>>");
        preview[i].setPosition(1660,270+i*100);
    }

    toraa.setFont(fontdig);
    toraa.setCharacterSize(75);
    toraa.setColor(sf::Color::Red);
    toraa.setPosition(630,370);

    tmina.setFont(fontdig);
    tmina.setCharacterSize(75);
    tmina.setColor(sf::Color::Red);
    tmina.setPosition(830,370);


    wakemeup.setCharacterSize(45);
    wakemeup.setColor(Color(77,33,0,255));
    wakemeup.setFont(font);
    wakemeup.setPosition(200,400);
    wakemeup.setString("Trezeste-ma la ora: ");

    sound.setCharacterSize(45);
    sound.setColor(Color(77,33,0,255));
    sound.setFont(font);
    sound.setPosition(1000,400);
    sound.setString("Cu sunetul: ");


    CircleShape pct1(5);
    CircleShape pct2(5);
    pct1.setFillColor(sf::Color::Red);
    pct2.setFillColor(sf::Color::Red);
    pct1.setPosition(790,410);
    pct2.setPosition(790,440);


    for(int i=0;i<=1;i++){
        plus[i].setString("+");
        minus[i].setString("-");
        plus[i].setFont(font);
        minus[i].setFont(font);
        plus[i].setColor(Color::Black);
        minus[i].setColor(Color::Black);
        plus[i].setCharacterSize(40);
        minus[i].setCharacterSize(50);
    }
    plus[0].setPosition(653,490);
    plus[1].setPosition(853,490);
    minus[0].setPosition(706,480);
    minus[1].setPosition(906,480);
    srand(time(NULL));
    textura.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\blue.jpg");
    sprit.setTexture(textura);
    bool alarma_a_sunat=false;

    time_t timp_curent;
    timp_curent=time(NULL);
    tm* timp_local=localtime(&timp_curent);

    int min=30;
    int ora=timp_local->tm_hour-1;

    Text topt[4];
    for(int i=0;i<=3;i++){
        topt[i].setFont(font);
        topt[i].setColor(Color::White);
        topt[i].setCharacterSize(25);
        if(i==0) topt[i].setString(CLASICA);
        if(i==1) topt[i].setString(COCOS);
        if(i==2) topt[i].setString(SECURITATE);
        if(i==3) topt[i].setString(NAVA);
    }
    topt[0].setPosition(1250,270);
    topt[1].setPosition(1250,370);
    topt[2].setPosition(1250,470);
    topt[3].setPosition(1250,570);

    while(alarma.isOpen()){
        Event event;

        while(alarma.pollEvent(event)){
            if(event.type==Event::Closed) alarma.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            std::cout<<"Ceasul a fost inchis!"<<std::endl;
            alarma.close();
            }
            //plus la ora
            if(Mouse::getPosition().x>=650&&Mouse::getPosition().x<=680&&Mouse::getPosition().y>=500&&Mouse::getPosition().y<=529)
            {
                mici[0].setFillColor(Color::Red);
                if(event.type==Event::MouseButtonPressed){
                    if(ora<23) ora++;
                    else ora=0;
                }
            }
            else mici[0].setFillColor(Color::White);

            //minus la ora
            if(Mouse::getPosition().x>=700&&Mouse::getPosition().x<=730&&Mouse::getPosition().y>=500&&Mouse::getPosition().y<=529){
                  mici[1].setFillColor(Color::Red);
                  if(event.type==Event::MouseButtonPressed){
                    if(ora>0) ora--;
                    else ora=23;
                  }
            }

            //plus la minut
            else mici[1].setFillColor(Color::White);
            if(Mouse::getPosition().x>=850&&Mouse::getPosition().x<=880&&Mouse::getPosition().y>=500&&Mouse::getPosition().y<=529){
                mici[2].setFillColor(Color::Red);
                if(event.type==Event::MouseButtonPressed){
                    if(min<59) min++;
                    else min=0;
                }
            }
            else mici[2].setFillColor(Color::White);

            //minus la minut
            if(Mouse::getPosition().x>=900&&Mouse::getPosition().x<=930&&Mouse::getPosition().y>=500&&Mouse::getPosition().y<=529){
                mici[3].setFillColor(Color::Red);
                if(event.type==Event::MouseButtonPressed){
                    if(min>0) min--;
                    else min=59;
                }
            }
            else mici[3].setFillColor(Color::White);

            if(Mouse::getPosition().x>=720&&Mouse::getPosition().x<=880&&Mouse::getPosition().y>=620&&Mouse::getPosition().y<=680)
               {
                start.setColor(Color::Black);
                cancel.setColor(Color::Black);
                if(event.type==Event::MouseButtonPressed){
                    last=!last;
                }
               }
            else {
                start.setColor(Color::White);
                cancel.setColor(Color::White);
            }

            if(Mouse::getPosition().x<=1800&&Mouse::getPosition().x>=1660&&Mouse::getPosition().y<=290&&Mouse::getPosition().y>=270){
                preview[0].setColor(Color::White);
                if(event.type==Event::MouseButtonPressed){
                    a1.setLoop(false);
                    a1.setPlayingOffset(seconds(5.f));
                    a1.play();
                }
            }
            else preview[0].setColor(Color::Black);
            if(Mouse::getPosition().x<=1800&&Mouse::getPosition().x>=1660&&Mouse::getPosition().y<=400&&Mouse::getPosition().y>=380){
                preview[1].setColor(Color::White);
                if(event.type==Event::MouseButtonPressed){
                    a2.setLoop(false);
                    a2.play();
                }
            }
            else preview[1].setColor(Color::Black);


            if(Mouse::getPosition().x<=1800&&Mouse::getPosition().x>=1660&&Mouse::getPosition().y<=500&&Mouse::getPosition().y>=480){
                preview[2].setColor(Color::White);
                if(event.type==Event::MouseButtonPressed){
                    a3.setLoop(false);
                    a3.setPlayingOffset(seconds(5.f));
                    a3.play();
                }
            }
            else preview[2].setColor(Color::Black);


            if(Mouse::getPosition().x<=1800&&Mouse::getPosition().x>=1660&&Mouse::getPosition().y<=600&&Mouse::getPosition().y>=580){
                preview[3].setColor(Color::White);
                if(event.type==Event::MouseButtonPressed){
                    a4.setLoop(false);
                    a4.setPlayingOffset(seconds(33.f));
                    a4.play();
                }
            }
            else preview[3].setColor(Color::Black);
        }
        time_t timp_curent;
        timp_curent=time(NULL);
        tm* timp_local=localtime(&timp_curent);
        int orabuna=timp_local->tm_hour;
        int minbun=timp_local->tm_min;
        sprintf(hal,"%d",ora);
        sprintf(mal,"%d",min);
        if(strlen(mal)==1){
         char aux=mal[0];
         mal[0]='0';
         mal[1]=aux;
         mal[2]=NULL;
        }
        if(strlen(hal)==1){
            char aux=hal[0];
            hal[0]='0';
            hal[1]=aux;
            hal[2]=NULL;
        }
        toraa.setString(hal);
        tmina.setString(mal);

        if(Mouse::getPosition().x>=1240&&Mouse::getPosition().x<=1640&&Mouse::getPosition().y>=280&&Mouse::getPosition().y<=330){
            optiuni[0].setFillColor(Color::Red);
            if(event.type==Event::MouseButtonPressed)
            {
                op1=true; op2=false; op3=false; op4=false;
            }
        }
        else optiuni[0].setFillColor(Color::Green);

        if(Mouse::getPosition().x>=1240&&Mouse::getPosition().x<=1640&&Mouse::getPosition().y>=380&&Mouse::getPosition().y<=430){
            optiuni[1].setFillColor(Color::Red);
            if(event.type==Event::MouseButtonPressed)
            {
                op1=false; op2=true; op3=false; op4=false;
            }
        }
        else optiuni[1].setFillColor(Color::Green);

        if(Mouse::getPosition().x>=1240&&Mouse::getPosition().x<=1640&&Mouse::getPosition().y>=480&&Mouse::getPosition().y<=530){
            optiuni[2].setFillColor(Color::Red);
            if(event.type==Event::MouseButtonPressed)
            {
                op1=false; op2=false; op3=true; op4=false;
            }
        }
        else optiuni[2].setFillColor(Color::Green);

        if(Mouse::getPosition().x>=1240&&Mouse::getPosition().x<=1640&&Mouse::getPosition().y>=580&&Mouse::getPosition().y<=630){
            optiuni[3].setFillColor(Color::Red);
            if(event.type==Event::MouseButtonPressed)
            {
                op1=false; op2=false; op3=false; op4=true;
            }
        }
        else optiuni[3].setFillColor(Color::Green);
        if(op1) optiuni[0].setFillColor(Color::Red);
        else if(op2) optiuni[1].setFillColor(Color::Red);
        else if(op3) optiuni[2].setFillColor(Color::Red);
        else if(op4) optiuni[3].setFillColor(Color::Red);

        alarma.draw(sprit);
        alarma.draw(sound);
        alarma.draw(wakemeup);
        alarma.draw(drept1);
        for(int i=0;i<4;i++) {alarma.draw(mici[i]); alarma.draw(optiuni[i]); alarma.draw(topt[i]); alarma.draw(preview[i]); }
        alarma.draw(plus[0]);
        alarma.draw(minus[0]);
        alarma.draw(plus[1]);
        alarma.draw(minus[1]);
        alarma.draw(pct1);
        alarma.draw(pct2);
        alarma.draw(tmina);
        alarma.draw(toraa);
        if(last){
            alarma.draw(startbutton);
            alarma.draw(start);
        }
        else {
            alarma.draw(cancelbutton);
            alarma.draw(cancel);
        }
        if(last==0&&(op1+op2+op3+op4)>0){
            if(orabuna==ora&&minbun==min){
                a1.setLoop(true);
                a2.setLoop(true);
                a3.setLoop(true);
                a4.setLoop(true);
                if(op1) a1.play();
                if(op2) a2.play();
                if(op3) a3.play();
                if(op4) a4.play();
                alarma_a_sunat=true;

            }
        }
        if(alarma_a_sunat) stop=1;
        if(stop==1) opreste_alarma.setString("Opreste alarma!");
        if(Mouse::getPosition().x>=630&&Mouse::getPosition().x<=950&&Mouse::getPosition().y<=260&&Mouse::getPosition().y>=225)
           {
            opreste_alarma.setColor(Color::Black);
            if(event.type==Event::MouseButtonPressed){
                a1.stop();
                a2.stop();
                a3.stop();
                a4.stop();
                stop=0;
                alarma_a_sunat=0;
            }
           }
        else opreste_alarma.setColor(Color::Red);
        if(alarma_a_sunat) last=1;
        if(stop==0) opreste_alarma.setString("");
        alarma.draw(opreste_alarma);
        alarma.display();
    }
}
