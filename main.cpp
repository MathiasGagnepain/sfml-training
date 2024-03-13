#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 700), "SFML works!");
    sf::CircleShape shape(100.f);

    sf::Texture texture;
    sf::Sprite background;
    texture.loadFromFile("background.jpg");
    background.setTexture(texture);
    background.setScale(2, 2);
    

    shape.setOutlineThickness(2);
    shape.setOutlineColor(sf::Color::Blue);

    sf::Texture character;
    character.loadFromFile("character.png");
    shape.setTexture(&character);

    int x = 1200 / 2 - 100;
    int y = 700 / 2 - 100;

    while (window.isOpen())
    {   
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && x > 0)
        {
            x--;
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && x < 1200- 200)
        {
            x++;
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && y > 0)
        {
            y--;
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && y < 700- 200)
        {
           y++;
        }
        
        shape.setPosition(x, y);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(background);
        window.draw(shape);
        window.display();
    }

    return 0;
}