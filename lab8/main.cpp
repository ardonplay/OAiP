#include <iostream>
#include <unistd.h>
#include <SFML/Graphics.hpp>
unsigned int microsecond = 0.1 * 1000000;
int main( )
{
    sf::RenderWindow window( sf::VideoMode( 640, 480 ), "Awesome Game" );

    sf::Texture texture;
    sf::Sprite sprite;
    //texture.setRepeated(true);

    texture.loadFromFile("../Gif/1.png");
    sprite.setTexture(texture);
    //sprite.setColor(sf::Color(255, 255, 255, 64));

    while ( window.isOpen( ) )
    {
        sf::Event event;

        // handle all events
        while ( window.pollEvent( event ) )
        {
            switch ( event.type )
            {
                case sf::Event::Closed:
                    window.close( );

                    break;
            }
        }

        // update the game
        window.clear( );
        window.draw(sprite);
        window.display( );
        for(int i = 1; i <=5;i++) {
            usleep(microsecond);
            window.clear();
            std::cout<<i<<std::endl;
            texture.loadFromFile("../Gif/" + std::to_string(i) + ".png");
            sprite.setTexture(texture);
            window.draw(sprite);
            window.display( );
        }
    }

    return EXIT_SUCCESS;
}
