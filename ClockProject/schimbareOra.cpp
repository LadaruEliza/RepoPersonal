#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
void schimbaOra(){
    RenderWindow window(VideoMode(800, 600),"Cand se schimba ora?",Style::Default);
    Sprite sprite;
    Texture texture;
    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\blackpic.jpg");
    sprite.setTexture(texture);
    Font font;
    font.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\lato\\Lato-BoldItalic.ttf");
    Text titlu;
    titlu.setFont(font);
    titlu.setColor(Color::White);
    titlu.setOutlineThickness(3.0f);
    titlu.setCharacterSize(20);
    titlu.setString("Mai jos, aveti o lista cuprinzand anul si data cand se schimba ora, pana in anul 2029:");
    titlu.setPosition(50,160);
    Text ani[7],info[7];
    for(int i=0;i<7;i++){
        ani[i].setFont(font);
        ani[i].setCharacterSize(18);
        ani[i].setOutlineThickness(2.0f);
        ani[i].setColor(Color::Red);
        info[i].setFont(font);
        info[i].setColor(Color::White);
        info[i].setCharacterSize(17);
        info[i].setOutlineThickness(2.0f);
        ani[i].setPosition(70,230+i*50);
        info[i].setPosition(120,230+i*50);
    }
    ani[0].setString("2023:");
    ani[1].setString("2024:");
    ani[2].setString("2025:");
    ani[3].setString("2026:");
    ani[4].setString("2027:");
    ani[5].setString("2028:");
    ani[6].setString("2029:");
    info[0].setString("Duminica 26 Martie +1 ora (ora de vara)        Duminica 29 Octombrie -1 ora (ora de iarna)");
    info[1].setString("Duminica 31 Martie +1 ora (ora de vara)        Duminica 27 Octombrie -1 ora (ora de iarna)");
    info[2].setString("Duminica 30 Martie +1 ora (ora de vara)        Duminica 26 Octombrie -1 ora (ora de iarna)");
    info[3].setString("Duminica 29 Martie +1 ora (ora de vara)        Duminica 25 Octombrie -1 ora (ora de iarna)");
    info[4].setString("Duminica 28 Martie +1 ora (ora de vara)        Duminica 31 Octombrie -1 ora (ora de iarna)");
    info[5].setString("Duminica 26 Martie +1 ora (ora de vara)        Duminica 29 Octombrie -1 ora (ora de iarna)");
    info[6].setString("Duminica 25 Martie +1 ora (ora de vara)        Duminica 28 Octombrie -1 ora (ora de iarna)");
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed)
                window.close();
            if(event.type==Event::KeyPressed){
                if(Keyboard::isKeyPressed(Keyboard::Escape))
                    window.close();
        }
    }
    window.draw(sprite);
    window.draw(titlu);
    for(int i=0;i<7;i++) {window.draw(ani[i]); window.draw(info[i]);}
    window.display();
}
}
