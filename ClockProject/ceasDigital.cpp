#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>
using namespace std;
using namespace sf;
void ceasDigital(){
char last[50];
time_t timp_curent;
timp_curent=time(NULL);
tm* timp_local=localtime(&timp_curent);
int buna=timp_local->tm_hour;
int ora=timp_local->tm_hour;
int zi=timp_local->tm_wday;
int luna=timp_local->tm_mon;
int an=timp_local->tm_year;
int ziualunii=timp_local->tm_mday;
char lunastr[25];
if(luna==0) strcpy(lunastr,"Ianuarie");
if(luna==1) strcpy(lunastr,"Februarie");
if(luna==2) strcpy(lunastr,"Martie");
if(luna==3) strcpy(lunastr,"Aprilie");
if(luna==4) strcpy(lunastr,"Mai");
if(luna==5) strcpy(lunastr,"Iunie");
if(luna==6) strcpy(lunastr,"Iulie");
if(luna==7) strcpy(lunastr,"August");
if(luna==8) strcpy(lunastr,"Septembrie");
if(luna==9) strcpy(lunastr,"Octombrie");
if(luna==10) strcpy(lunastr,"Noiembrie");
if(luna==11) strcpy(lunastr,"Decembrie");
char anul[5];
char ziluna[15];
sprintf(anul,"%d",an+1900);
sprintf(ziluna,"%d",ziualunii);
char ziua[25];
if(zi==0) strcpy(ziua,"Duminica, ");
else if(zi==1) strcpy(ziua,"Luni, ");
else if(zi==2) strcpy(ziua,"Marti, ");
else if(zi==3) strcpy(ziua,"Miercuri, ");
else if(zi==4) strcpy(ziua,"Joi, ");
else if(zi==5) strcpy(ziua,"Vineri, ");
else if(zi==6) strcpy(ziua,"Sambata, ");
strcat(ziua,ziluna);
strcat(ziua," ");
strcat(ziua,lunastr);
strcat(ziua," ");
strcat(ziua,anul);
char s[25];
char m[25];
char h[25];
char g[]="GMT";
char g1[]="GMT +1";
char g2[]="GMT +2";
char g3[]="GMT +3";
char g4[]="GMT +4";
char g5[]="GMT +5";
bool ok=false,ok1=false,ok2=false,ok3=false,ok4=false,ok5=false;

   sf::Font font;
   font.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\digitalnumbers-regular.ttf");

   Font font2;
   font2.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\Quicksand-Regular.otf");

   sf::CircleShape pct1(10);
   sf::CircleShape pct2(10);
   sf::CircleShape pct3(10);
   sf::CircleShape pct4(10);

   pct4.setFillColor(sf::Color::White);
   pct1.setFillColor(sf::Color::White);
   pct2.setFillColor(sf::Color::White);
   pct3.setFillColor(sf::Color::White);
   int x1=700;
   int x2=1010;
   int y1=430;
   int y2=550;
   pct1.setPosition(x1,y1);
   pct2.setPosition(x1,y2);
   pct3.setPosition(x2,y1);
   pct4.setPosition(x2,y2);

   sf::Text tsec;
   tsec.setFont(font);
   tsec.setCharacterSize(150);
   tsec.setColor(sf::Color::White);
   tsec.setPosition(1042,394);

   sf::Text tmin;
   tmin.setFont(font);
   tmin.setCharacterSize(150);
   tmin.setColor(sf::Color::White);
   tmin.setPosition(732,394);

   sf::Text tora;
   tora.setFont(font);
   tora.setCharacterSize(150);
   tora.setColor(sf::Color::White);
   tora.setPosition(420,394);

   sf::RenderWindow window(sf::VideoMode(1920,1080), "Ceas Digital",Style::Fullscreen);
   window.setFramerateLimit(60);
   srand(time(NULL));
   sf::Texture texture;
   if (!texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\blackpic.jpg"))
    {
      std::cout<<"FAIL";
      exit(1);
    }
   sf::Sprite sprite;
   sprite.setTexture(texture);

   Texture galben;
   galben.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\galben.jpg");
   Texture albastru;
   albastru.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\albastru.jpg");
   Texture maro;
   maro.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\maro.jpg");
   Texture porto;
   porto.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\portocaliu.jpg");
   Text tzi;
   tzi.setFont(font2);
   tzi.setCharacterSize(50);
   tzi.setColor(Color::White);
   tzi.setString(ziua);
   tzi.setPosition(515,670);

   Text tz,tz1,tz2,tz3,tz4,tz5,top;

   top.setCharacterSize(60);
   top.setColor(Color::White);
   top.setPosition(550,35);
   top.setFont(font2);
   top.setString("Alegeti un time-zone!");

   tz.setCharacterSize(35);
   tz1.setCharacterSize(35);
   tz2.setCharacterSize(35);
   tz3.setCharacterSize(35);
   tz4.setCharacterSize(35);
   tz5.setCharacterSize(35);

   tz.setString(g);
   tz1.setString(g1);
   tz2.setString(g2);
   tz3.setString(g3);
   tz4.setString(g4);
   tz5.setString(g5);

   tz.setFont(font2);
   tz1.setFont(font2);
   tz2.setFont(font2);
   tz3.setFont(font2);
   tz4.setFont(font2);
   tz5.setFont(font2);

   tz.setColor(Color::Green);
   tz1.setColor(Color::Green);
   tz2.setColor(Color::Green);
   tz3.setColor(Color::Green);
   tz4.setColor(Color::Green);
   tz5.setColor(Color::Green);

   int x=250,y=150;
   tz.setPosition(x,y);
   tz1.setPosition(x+190,y);
   tz2.setPosition(x+450,y);
   tz3.setPosition(x+700,y);
   tz4.setPosition(x+950,y);
   tz5.setPosition(x+1200,y);

   strcpy(last,"Time-zone selectat: GMT+2");
   Text tTimezoneAles;

   tTimezoneAles.setCharacterSize(45);
   tTimezoneAles.setFont(font2);
   tTimezoneAles.setColor(Color::Magenta);
   tTimezoneAles.setPosition(570,260);
   tTimezoneAles.setString(last);


   CircleShape cercrosu(14);
   cercrosu.setFillColor(Color::Red);
   cercrosu.setPosition(1890,293);
   bool okcerc=false;

   Text tx;
   tx.setColor(Color::Black);
   tx.setPosition(1896,286);
   tx.setFont(font2);
   tx.setString("x");

   Text schimbati;
   schimbati.setColor(Color::White);
   schimbati.setFont(font2);
   schimbati.setCharacterSize(30);
   schimbati.setString("Schimbati culoarea background-ului:");
   schimbati.setPosition(100,950);

   Text option[5];
   for(int i=0;i<5;i++){
      option[i].setCharacterSize(30);
      option[i].setFont(font2);
      option[i].setOutlineThickness(2.0f);
   }
   option[0].setPosition(680,950);
   option[1].setPosition(820,950);
   option[2].setPosition(980,950);
   option[3].setPosition(1100,950);
   option[4].setPosition(1280,950);

   option[0].setString("Galben");
   option[1].setString("Albastru");
   option[2].setString("Maro");
   option[3].setString("Portocaliu");
   option[4].setString("Default");
   option[0].setColor(Color::Yellow);
   option[1].setColor(Color::Blue);
   option[2].setColor(Color(205,127,50));
   option[3].setColor(Color(255,69,0));
   option[4].setColor(Color::White);

   //mici retusuri
   tTimezoneAles.setOutlineThickness(2.0f);
   top.setOutlineThickness(2.0f);
   tzi.setOutlineThickness(2.0f);
   tora.setColor(Color::Red);
   tmin.setColor(Color::Yellow);
   tsec.setColor(Color::Blue);
   while(window.isOpen()){
     sf::Event event;
     while(window.pollEvent(event)){
       if(event.type==sf::Event::Closed)
          window.close();

       if(event.type==sf::Event::KeyPressed)
       {
           // Atunci cand se apasa Escape, iesim din program
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            std::cout<<"Ceasul a fost inchis!"<<std::endl;
            window.close();
           }
       }
     }

      if(Mouse::getPosition().x<=780&&Mouse::getPosition().x>=670&&Mouse::getPosition().y<=990&&Mouse::getPosition().y>=960)
          {
            option[0].setColor(Color::Magenta);
            if(event.type==Event::MouseButtonPressed){
               sprite.setTexture(galben);
               tmin.setColor(Color::White);
               tora.setColor(Color::Red);
               tsec.setColor(Color::Blue);
            }
          }
      else option[0].setColor(Color::Yellow);

      if(Mouse::getPosition().x>=810&&Mouse::getPosition().x<=950&&Mouse::getPosition().y>=960&&Mouse::getPosition().y<=990)
      {
         option[1].setColor(Color::Magenta);
         if(event.type==Event::MouseButtonPressed){
            sprite.setTexture(albastru);
            tsec.setColor(Color::White);
            tmin.setColor(Color::Yellow);
            tora.setColor(Color::Red);
         }
      }
      else option[1].setColor(Color::Blue);

      if(Mouse::getPosition().x>=980&&Mouse::getPosition().x<=1055&&Mouse::getPosition().y>=960&&Mouse::getPosition().y<=990)
      {
         option[2].setColor(Color::Magenta);
         if(event.type==Event::MouseButtonPressed){
            tora.setColor(Color::Red);
            tmin.setColor(Color::Yellow);
            tsec.setColor(Color::Blue);
            sprite.setTexture(maro);
         }
      }
      else option[2].setColor(Color(205,127,50));

      if(Mouse::getPosition().x>=1100&&Mouse::getPosition().x<=1250&&Mouse::getPosition().y>=960&&Mouse::getPosition().y<=990)
      {
         option[3].setColor(Color::Magenta);
         if(event.type==Event::MouseButtonPressed){
            sprite.setTexture(porto);
            tora.setColor(Color::Red);
            tmin.setColor(Color::Yellow);
            tsec.setColor(Color::Blue);
         }
      }
      else option[3].setColor(Color(255,69,0));

      if(Mouse::getPosition().x>=1290&&Mouse::getPosition().x<=1385&&Mouse::getPosition().y>=960&&Mouse::getPosition().y<=990)
      {
         option[4].setColor(Color::Magenta);
         if(event.type==Event::MouseButtonPressed){
            sprite.setTexture(texture);
            tora.setColor(Color::Red);
            tmin.setColor(Color::Yellow);
            tsec.setColor(Color::Blue);
         }
      }
      else option[4].setColor(Color::White);

      time_t timp_curent;
      timp_curent=time(NULL);
      tm* timp_local=localtime(&timp_curent);
      int sec=timp_local->tm_sec;
      int min=timp_local->tm_min;
         if(Mouse::getPosition().y<=190&&Mouse::getPosition().y>=150&&Mouse::getPosition().x>=250&&Mouse::getPosition().x<=350){
           tz.setColor(Color::Red);
           if(event.type==Event::MouseButtonPressed){
             ora=buna-2;
             strcpy(last,"Time-zone selectat: GMT");
             tTimezoneAles.setString(last);
             ok=true;
             ok1=false; ok2=false; ok3=false; ok4=false; ok5=false;
             okcerc=true;
           }
      }
      else tz.setColor(Color::Green);

      if(Mouse::getPosition().y<=190&&Mouse::getPosition().y>=150&&Mouse::getPosition().x>=440&&Mouse::getPosition().x<=620)
         {
            tz1.setColor(Color::Red);
            if(event.type==Event::MouseButtonPressed)
               {
                  ora=buna-1;
                  strcpy(last,"Time-zone selectat: GMT+1");
                  tTimezoneAles.setString(last);
                  ok1=true;
                  ok=false; ok2=false; ok3=false; ok4=false; ok5=false;
                  okcerc=true;
               }
         }
      else tz1.setColor(Color::Green);

      if(Mouse::getPosition().y<=190&&Mouse::getPosition().y>=150&&Mouse::getPosition().x>=700&&Mouse::getPosition().x<=870)
         {
            tz2.setColor(Color::Red);
            if(event.type==Event::MouseButtonPressed)
               {
                  ora=buna;
                  strcpy(last,"Time-zone selectat: GMT+2");
                  tTimezoneAles.setString(last);
                  ok2=true;
                  ok1=false; ok=false; ok3=false; ok4=false; ok5=false;
                  okcerc=true;
               }
         }
      else tz2.setColor(Color::Green);

      if(Mouse::getPosition().y<=190&&Mouse::getPosition().y>=150&&Mouse::getPosition().x>=960&&Mouse::getPosition().x<=1120)
         {
            tz3.setColor(Color::Red);
            if(event.type==Event::MouseButtonPressed)
               {
                  ora=buna+1;
                  strcpy(last,"Time-zone selectat: GMT+3");
                  tTimezoneAles.setString(last);
                  ok3=true;
                  ok1=false; ok2=false; ok=false; ok4=false; ok5=false;
                  okcerc=true;
               }
            if(ora>=24) ora=ora-24;
         }
      else tz3.setColor(Color::Green);

      if(Mouse::getPosition().y<=190&&Mouse::getPosition().y>=150&&Mouse::getPosition().x>=1210&&Mouse::getPosition().x<=1360)
         {
            tz4.setColor(Color::Red);
            if(event.type==Event::MouseButtonPressed)
               {
                  ora=buna+2;
                  strcpy(last,"Time-zone selectat: GMT+4");
                  tTimezoneAles.setString(last);
                  ok4=true;
                  ok1=false; ok2=false; ok3=false; ok=false; ok5=false;
                  okcerc=true;
               }

            if(ora>=24) ora=ora-24;
         }
      else tz4.setColor(Color::Green);

      if(Mouse::getPosition().y<=190&&Mouse::getPosition().y>=150&&Mouse::getPosition().x>=1450&&Mouse::getPosition().x<=1600)
         {
            tz5.setColor(Color::Red);
            if(event.type==Event::MouseButtonPressed)
                {
                  ora=buna+3;
                  strcpy(last,"Time-zone selectat: GMT+5");
                  tTimezoneAles.setString(last);

                  ok5=true;
                  ok1=false; ok2=false; ok3=false; ok4=false; ok=false;
                  okcerc=true;
                }
            if(ora>=24) ora=ora-24;
         }
      else tz5.setColor(Color::Green);

      if(Mouse::getPosition().x>=1875&&Mouse::getPosition().x<=1905&&Mouse::getPosition().y>=280&&Mouse::getPosition().y<=310)
         {
            cercrosu.setFillColor(Color::White);
            if(event.type==Event::MouseButtonPressed){
               window.close();
               ceasDigital();
            }
         }
      else cercrosu.setFillColor(Color::Red);

      sprintf(s,"%d",sec);
      sprintf(m,"%d",min);
      sprintf(h,"%d",ora);
      if(strlen(s)==1){
         char aux=s[0];
         s[0]='0';
         s[1]=aux;
         s[2]=NULL;
      }
      if(strlen(m)==1){
         char aux=m[0];
         m[0]='0';
         m[1]=aux;
         m[2]=NULL;
      }
      if(strlen(h)==1){
         char aux=h[0];
         h[0]='0';
         h[1]=aux;
         h[2]=NULL;
      }
      if(timp_local->tm_sec%4==0){
         pct1.setFillColor(Color::Red);
         pct2.setFillColor(Color::Yellow);
         pct3.setFillColor(Color::Cyan);
         pct4.setFillColor(Color::Green);
      }
      else if(timp_local->tm_sec%4==1){
         pct1.setFillColor(Color::Cyan);
         pct2.setFillColor(Color::Green);
         pct3.setFillColor(Color::Red);
         pct4.setFillColor(Color::Yellow);
      }
      else if(timp_local->tm_sec%4==2){
         pct1.setFillColor(Color::Yellow);
         pct2.setFillColor(Color::Cyan);
         pct3.setFillColor(Color::Green);
         pct4.setFillColor(Color::Red);
      }
      else {
         pct1.setFillColor(Color::Green);
         pct2.setFillColor(Color::Red);
         pct3.setFillColor(Color::Yellow);
         pct4.setFillColor(Color::Cyan);
      }

      pct1.setOutlineThickness(3.0f);
      pct2.setOutlineThickness(3.0f);
      pct3.setOutlineThickness(3.0f);
      pct4.setOutlineThickness(3.0f);

      tsec.setString(s);
      tmin.setString(m);
      tora.setString(h);
      window.draw(sprite); // background-ul
      window.draw(tsec);
      window.draw(tmin);
      window.draw(tora);
      window.draw(pct1);
      window.draw(pct2);
      window.draw(pct3);
      window.draw(pct4);
      window.draw(tz);
      window.draw(tz1);
      window.draw(tz2);
      window.draw(tz3);
      window.draw(tz4);
      window.draw(tz5);
      window.draw(top);
      window.draw(tzi);
      window.draw(tTimezoneAles);
      window.draw(schimbati);
      for(int i=0;i<5;i++) window.draw(option[i]);
      window.display();
   }
}
