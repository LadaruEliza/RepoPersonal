#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
void calendar()
{
    RenderWindow window(VideoMode(1920,1080),"Calendar",Style::Fullscreen);
    Sprite sprite;
    Texture texture;
    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\1.jpg");
    sprite.setTexture(texture);

    int contor=0;
    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
                window.close();
            if(event.type==Event::KeyPressed)
            {
                if(Keyboard::isKeyPressed(Keyboard::Escape))
                    window.close();
                if(Keyboard::isKeyPressed(Keyboard::Left))
                    if (contor>0) contor--;
                if(Keyboard::isKeyPressed(Keyboard::Right))
                        if (contor<12) contor++;}
                if (contor==0)
                {
                    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\1.jpg");
                    sprite.setTexture(texture);
                }

                if (contor==1)
                {
                    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\2.jpg");
                    sprite.setTexture(texture);
                }

                if (contor==2)
                {
                    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\3.jpg");
                    sprite.setTexture(texture);
                }

                if (contor==3)
                {
                    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\4.jpg");
                    sprite.setTexture(texture);
                }

                if (contor==4)
                {
                    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\5.jpg");
                    sprite.setTexture(texture);
                }

                if (contor==5)
                {
                    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\6.jpg");
                    sprite.setTexture(texture);
                }

                if (contor==6)
                {
                    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\7.jpg");
                    sprite.setTexture(texture);
                }

                if (contor==7)
                {
                    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\8.jpg");
                    sprite.setTexture(texture);
                }

                if (contor==8)
                {
                    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\9.jpg");
                    sprite.setTexture(texture);
                }

                if (contor==9)
                {
                    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\10.jpg");
                    sprite.setTexture(texture);
                }

                if (contor==10)
                {
                    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\11.jpg");
                    sprite.setTexture(texture);
                }

                if (contor==11)
                {
                    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\12.jpg");
                    sprite.setTexture(texture);
                }

                if (contor==12)
                {
                    texture.loadFromFile("C:\\Users\\eliza\\OneDrive\\Desktop\\testsfml\\13.jpg");
                    sprite.setTexture(texture);
                }

            window.draw(sprite);
            window.display();
        }
    }
}
