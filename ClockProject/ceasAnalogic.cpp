#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
using namespace sf;
void ceasAnalogic(){
    char s[3],m[3],h[3];
	char orase[9][25];
	char taste[9][10];
	strcpy(orase[0],"Londra");
	strcpy(taste[0],"L");

	strcpy(orase[1],"Dubai");
	strcpy(taste[1],"D");

	strcpy(orase[2],"Paris");
	strcpy(taste[2],"P");

    strcpy(orase[3],"Madrid");
	strcpy(taste[3],"M");

	strcpy(orase[4],"Viena");
	strcpy(taste[4],"V");

	strcpy(orase[5],"Tokyo");
	strcpy(taste[5],"T");

	strcpy(orase[6],"Atena");
	strcpy(taste[6],"A");

	strcpy(orase[7],"Berlin");
	strcpy(taste[7],"B");

	strcpy(orase[8],"Oslo");
	strcpy(taste[8],"O");

	char culoare[5][20];
	strcpy(culoare[0],"Default");
	strcpy(culoare[1],"Galben");
	strcpy(culoare[2],"Alb");
	strcpy(culoare[3],"Bleu");
	strcpy(culoare[4],"Transparent");

    Sprite sprite;
    Texture texture;
    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\blackpic.jpg");
    sprite.setTexture(texture);

    Font font;
    font.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\Lato-BoldItalic.ttf");

    Text toras;
    toras.setCharacterSize(45);
	toras.setColor(Color::White);
	toras.setFont(font);
	toras.setString("Pentru a vedea ora in:");
	toras.setPosition(80,120);
    toras.setOutlineThickness(3.0f);

    Text ttasta;
    ttasta.setCharacterSize(45);
	ttasta.setColor(Color::White);
	ttasta.setFont(font);
	ttasta.setString("Apasati tasta:");
	ttasta.setPosition(150,320);
	ttasta.setOutlineThickness(3.0f);

    int contor=0;
	Text selectie_oras,selectie_tasta;
	selectie_oras.setCharacterSize(35);
	selectie_oras.setFont(font);
	selectie_oras.setString(orase[contor]);
	selectie_oras.setColor(Color::Blue);
	selectie_oras.setPosition(245,215);
    selectie_oras.setOutlineThickness(6.0f);

    selectie_tasta.setCharacterSize(35);
	selectie_tasta.setFont(font);
	selectie_tasta.setColor(Color::Blue);
	selectie_tasta.setString(taste[contor]);
	selectie_tasta.setPosition(280,415);
    selectie_tasta.setOutlineThickness(6.0f);

    Text sageata_stanga,sageata_dreapta;
	sageata_dreapta.setCharacterSize(50);
	sageata_dreapta.setColor(Color::White);
	sageata_dreapta.setFont(font);
	sageata_dreapta.setString(">");
	sageata_dreapta.setPosition(400,205);

	sageata_stanga.setCharacterSize(50);
	sageata_stanga.setColor(Color::White);
	sageata_stanga.setFont(font);
	sageata_stanga.setString("<");
	sageata_stanga.setPosition(130,205);

    RectangleShape dr1;
	dr1.setSize(Vector2f(300,75));
	dr1.setFillColor(Color::Transparent);
	dr1.setOutlineColor(Color::Black);
	dr1.setOutlineThickness(3.0f);
	dr1.setPosition(130,200);


    RectangleShape dr2;
	dr2.setSize(Vector2f(300,75));
	dr2.setFillColor(Color::Transparent);
	dr2.setOutlineColor(Color::Black);
	dr2.setOutlineThickness(3.0f);
	dr2.setPosition(130,400);

    Text t12,t9,t3,t6,t10,t11,t1,t2,t4,t5,t7,t8;
    t3.setFont(font);
    t6.setFont(font);
    t9.setFont(font);
    t12.setFont(font);
	t1.setFont(font);
	t2.setFont(font);
	t4.setFont(font);
	t5.setFont(font);
	t8.setFont(font);
	t7.setFont(font);
	t10.setFont(font);
	t11.setFont(font);
	t1.setCharacterSize(50);
	t2.setCharacterSize(50);
	t4.setCharacterSize(50);
	t5.setCharacterSize(50);
	t7.setCharacterSize(50);
	t8.setCharacterSize(50);
	t10.setCharacterSize(47);
	t11.setCharacterSize(47);
	t1.setColor(Color::Black);
	t2.setColor(Color::Black);
	t5.setColor(Color::Black);
	t4.setColor(Color::Black);
	t7.setColor(Color::Black);
	t8.setColor(Color::Black);
	t10.setColor(Color::Black);
	t11.setColor(Color::Black);
	t1.setString("1");
	t2.setString("2");
	t4.setString("4");
	t5.setString("5");
	t7.setString("7");
	t8.setString("8");
	t10.setString("10");
	t11.setString("11");
    t3.setColor(Color::Black);
    t6.setColor(Color::Black);
    t9.setColor(Color::Black);
    t12.setColor(Color::Black);
    t3.setCharacterSize(50);
    t6.setCharacterSize(50);
    t9.setCharacterSize(50);
    t12.setCharacterSize(50);
    t3.setPosition(1380,500);
    t6.setPosition(950,920);
    t9.setPosition(510,490);
    t12.setPosition(940,60);
    t3.setString("3");
    t6.setString("6");
    t9.setString("9");
    t12.setString("12");

    t10.setPosition(570,280);
	t8.setPosition(575,696);
	t2.setPosition(1315,270);
	t4.setPosition(1315,696);
	t7.setPosition(735,860);
	t11.setPosition(730,120);
	t1.setPosition(1155,120);
	t5.setPosition(1155,860);

	sf::RenderWindow Window (sf::VideoMode (1920,1080, 32), "Clock",Style::Fullscreen);

	float raza_cerc = 450;
	float clockX = 510;
	float clockY = 70;

	float centerX = clockX + raza_cerc;
	float centerY = clockY + raza_cerc;

	sf::CircleShape clock (raza_cerc, 360U	);
	clock.setPosition (clockX, clockY);
	clock.setOutlineThickness (1.0);
	clock.setOutlineColor (sf::Color::Black);
	clock.setFillColor (sf::Color::Magenta);

	float razacentru = 20;

	sf::CircleShape centerCircle = sf::CircleShape(razacentru, 360);
	centerCircle.setPosition (centerX - razacentru, centerY - razacentru);
	centerCircle.setFillColor (sf::Color::Black);

	float desen_oraLength = (8.0/14.0) * raza_cerc;
	float desen_minutLength = (9.0/11.0) * raza_cerc;
	float desen_secundaLength = (10.0/11.0) * raza_cerc;

	float desen_oraWidth = 3.0;
	float desen_minutWidth = 3.0;
	float desen_secundaWidth = 3.0;

	float hour = 0.0;
	float minute = 0.0;
	float second = 0.0;

	float orar = 0.0;
	float minutar = 0.0;
	float secundar = 0.0;

	sf::RectangleShape desen_ora;
	desen_ora.setPosition (centerX, centerY - desen_oraWidth / 2);
	desen_ora.setSize (sf::Vector2f (desen_oraLength, desen_oraWidth));
	desen_ora.setFillColor (sf::Color::Green);
	desen_ora.setOutlineThickness(3.0f);
    desen_ora.setOutlineColor(Color::Black);

	sf::RectangleShape desen_minut;
	desen_minut.setPosition (centerX, centerY - desen_minutWidth / 2);
	desen_minut.setSize (sf::Vector2f (desen_minutLength, desen_minutWidth));
	desen_minut.setFillColor (sf::Color::Blue);
	desen_minut.setOutlineThickness(3.0f);
	desen_minut.setOutlineColor(Color::Black);

	sf::RectangleShape desen_secunda;
	desen_secunda.setPosition (centerX, centerY - desen_secundaWidth / 2);
	desen_secunda.setSize (sf::Vector2f (desen_secundaLength, desen_secundaWidth));
	desen_secunda.setFillColor (sf::Color::Red);
	desen_secunda.setOutlineThickness(3.0f);
    desen_secunda.setOutlineColor(Color::Black);

	int last=0;

    Text da_sau_nu,da,nu;
	da_sau_nu.setFont(font);
	da_sau_nu.setCharacterSize(40);
	da_sau_nu.setColor(Color::White);
	da_sau_nu.setOutlineThickness(2.0f);
	da_sau_nu.setString("Afisati ceasul digital?");
	da_sau_nu.setPosition(1450,150);

    da.setFont(font);
	da.setCharacterSize(35);
	da.setColor(Color::Green);
	da.setOutlineThickness(2.0f);
	da.setString("Da");
	da.setPosition(1550,220);

	nu.setFont(font);
	nu.setCharacterSize(35);
	nu.setColor(Color::Red);
	nu.setString("Nu");
	nu.setOutlineThickness(2.0f);
	nu.setPosition(1650,220);

	Text doua_puncte[2];
	for(int i=0;i<=1;i++){
		doua_puncte[i].setFont(font);
		doua_puncte[i].setCharacterSize(35);
		doua_puncte[i].setColor(Color::White);
		doua_puncte[i].setString("");
		doua_puncte[i].setOutlineThickness(3.0f);
	}
	doua_puncte[0].setPosition(930,422);
	doua_puncte[1].setPosition(990,422);
	bool da_apasat=false,nu_apasat=false;

	Text tora,tmin,tsec;
	tora.setFont(font); tmin.setFont(font); tsec.setFont(font);
	tora.setCharacterSize(30); tmin.setCharacterSize(30); tsec.setCharacterSize(30);
	tora.setColor(Color::White); tmin.setColor(Color::White); tsec.setColor(Color::White);
	tora.setString(""); tmin.setString(""); tsec.setString("");
	tora.setOutlineThickness(2.0f); tmin.setOutlineThickness(2.0f); tsec.setOutlineThickness(2.0f);
	tora.setPosition(885,430); tmin.setPosition(945,430); tsec.setPosition(1005,430);

    RectangleShape cover_optiune,cover_culoare;
	cover_optiune.setSize(Vector2f(400,170));
	cover_optiune.setFillColor(Color::Transparent);
	cover_optiune.setOutlineColor(Color::Cyan);
	cover_optiune.setOutlineThickness(6.0f);
	cover_optiune.setPosition(1430,125);

    cover_culoare.setSize(Vector2f(400,50));
	cover_culoare.setFillColor(Color::Transparent);
	cover_culoare.setOutlineColor(Color::Black);
	cover_culoare.setOutlineThickness(6.0f);
	cover_culoare.setPosition(1435,870);

    Text alege_culoare;
	alege_culoare.setFont(font);
	alege_culoare.setCharacterSize(40);
	alege_culoare.setColor(Color::Cyan);
	alege_culoare.setOutlineThickness(4.0f);
	alege_culoare.setString("Alegeti culoarea ceasului");
	alege_culoare.setPosition(1420,800);

    Text culoare_curenta,spre_stanga,spre_dreapta;
	spre_dreapta.setCharacterSize(40); spre_dreapta.setFont(font); spre_dreapta.setColor(Color::White);
	spre_stanga.setCharacterSize(40); spre_stanga.setFont(font); spre_stanga.setColor(Color::White);
    spre_dreapta.setString(">"); spre_stanga.setString("<");
	spre_dreapta.setPosition(1800,870); spre_stanga.setPosition(1445,870);

	int prezent=0;
    culoare_curenta.setCharacterSize(35);
	culoare_curenta.setFont(font);
	culoare_curenta.setString(culoare[prezent]);
	culoare_curenta.setColor(Color::White);
	culoare_curenta.setPosition(1575,870);

	while (Window.isOpen ())
	{
		sf::Event Event;
        while(Window.pollEvent(Event)){
            if(Event.type==Event::Closed) Window.close();
            if(Event.type==Event::KeyPressed){
                if(Keyboard::isKeyPressed(Keyboard::Escape))
                    Window.close();
				switch(Event.key.code){
					case 0:
						last=0;
						break;
					case 1:
						last=-1;
						break;
					case 3:
						last=2;
						break;
					case 11:
						last=-2;
						break;
					case 12:
						last=-1;
						break;
					case 14:
						last=-1;
						break;
					case 15:
						last=-1;
						break;
					case 19:
						last=7;
						break;
					case 21:
						last=-1;
						break;
				}
				if(Keyboard::isKeyPressed(Keyboard::Tab)) prezent++;
            }
			if(Mouse::getPosition().x>=400&&Mouse::getPosition().x<=430&&Mouse::getPosition().y>=230&&Mouse::getPosition().y<=250){
				   sageata_dreapta.setColor(Color::Red);
				   if(Event.type==Event::MouseButtonPressed) contor++;
			}
			else sageata_dreapta.setColor(Color::White);

			if(Mouse::getPosition().x>=130&&Mouse::getPosition().x<=160&&Mouse::getPosition().y>=230&&Mouse::getPosition().y<=250){
				sageata_stanga.setColor(Color::Red);
				if(Event.type==Event::MouseButtonPressed){
					if(contor>0) contor--;
					else contor=8;
				}
			}
			else sageata_stanga.setColor(Color::White);

			if(Mouse::getPosition().x>=1540&&Mouse::getPosition().x<=1595&&Mouse::getPosition().y>=230&&Mouse::getPosition().y<=250){
				da.setColor(Color::White);
				if(Event.type==Event::MouseButtonPressed){
					da_apasat=true;
					nu_apasat=false;
				}
			}
			else da.setColor(Color::Green);

			if(Mouse::getPosition().x>=1650&&Mouse::getPosition().x<=1690&&Mouse::getPosition().y>=230&&Mouse::getPosition().y<=250){
				nu.setColor(Color::White);
				if(Event.type==Event::MouseButtonPressed){
					nu_apasat=true;
					da_apasat=false;
				}
			}
			else nu.setColor(Color::Red);

			if(Mouse::getPosition().x>=1445&&Mouse::getPosition().x<=1470&&Mouse::getPosition().y>=870&&Mouse::getPosition().y<=900){
				spre_stanga.setColor(Color::Red);
				if(Event.type==Event::MouseButtonPressed){
					if(prezent>0) prezent--;
					else prezent=4;
				}
			}
			else spre_stanga.setColor(Color::White);

			if(Mouse::getPosition().x>=1800&&Mouse::getPosition().x<=1820&&Mouse::getPosition().y>=870&&Mouse::getPosition().y<=900){
				spre_dreapta.setColor(Color::Red);
				if(Event.type==Event::MouseButtonPressed){
					prezent++;
				}
			}
			else spre_dreapta.setColor(Color::White);
        }
		culoare_curenta.setString(culoare[prezent%5]);
		switch(prezent%5){
			case 0:
				clock.setFillColor(Color::Magenta);
				culoare_curenta.setColor(Color::Magenta);
				break;
			case 1:
				clock.setFillColor(Color::Yellow);
				culoare_curenta.setColor(Color::Yellow);
				break;
			case 2:
			 	clock.setFillColor(Color::White);
				culoare_curenta.setColor(Color::White);
				break;
			case 3:
				clock.setFillColor(Color::Cyan);
				culoare_curenta.setColor(Color::Cyan);
				break;
			case 4:
				clock.setFillColor(Color::Transparent);
				culoare_curenta.setColor(Color::Black);
				break;
		}
		selectie_oras.setString(orase[contor%9]);
		selectie_tasta.setString(taste[contor%9]);
		time_t timp_curent;
        timp_curent=time(NULL);
        tm* timp_local=localtime(&timp_curent);
		second = timp_local->tm_sec;
		minute = timp_local->tm_min + second / 60;
		hour   = timp_local->tm_hour + minute / 60+last;

		int sec=timp_local->tm_sec;
      	int min=timp_local->tm_min;
		int ora=timp_local->tm_hour;
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
	  if(da_apasat){
		tora.setString(h);
		tmin.setString(m);
		tsec.setString(s);
		doua_puncte[0].setString(":");
		doua_puncte[1].setString(":");
	  }
	  else if(nu_apasat){
		//stergem cifrele
		tora.setString("");
		tmin.setString("");
		tsec.setString("");
		doua_puncte[0].setString("");
		doua_puncte[1].setString("");
	  }
		orar = (hour / 12.0) * 360.0 - 90.0;
		minutar = (minute / 60.0) * 360.0f - 90.0;
		secundar = (second / 60.0) * 360.0f - 90.0;
		desen_ora.setRotation (orar);
		desen_minut.setRotation (minutar);
		desen_secunda.setRotation (secundar);
        Window.draw(sprite);
		Window.draw(clock);
		Window.draw(centerCircle);
		Window.draw(desen_ora);
		Window.draw(desen_minut);
		Window.draw(desen_secunda);
        Window.draw(t3);
        Window.draw(t6);
        Window.draw(t9);
        Window.draw(t12);
		Window.draw(toras);
		Window.draw(dr1);
		Window.draw(ttasta);
		Window.draw(dr2);
		Window.draw(selectie_oras);
		Window.draw(selectie_tasta);
		Window.draw(sageata_dreapta);
		Window.draw(sageata_stanga);
		Window.draw(t1);
		Window.draw(t2);
		Window.draw(t4);
		Window.draw(t5);
		Window.draw(t7);
		Window.draw(t8);
		Window.draw(t10);
		Window.draw(t11);
		Window.draw(cover_optiune);
		Window.draw(da_sau_nu);
		Window.draw(da);
		Window.draw(nu);
		Window.draw(tora); Window.draw(tmin); Window.draw(tsec);
		Window.draw(doua_puncte[0]); Window.draw(doua_puncte[1]);
		Window.draw(cover_culoare);
		Window.draw(alege_culoare);
		Window.draw(spre_dreapta); Window.draw(spre_stanga);
		Window.draw(culoare_curenta);
		Window.display ();
	}
}
