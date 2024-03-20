#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Mario Game");

    // Load Mario texture
    sf::Texture marioTexture;
    if (!marioTexture.loadFromFile("mario.png")) {
        // Handle error
    }

    // Create Mario sprite
    sf::Sprite mario(marioTexture);
    mario.setPosition(100, 400); // Initial position of Mario

    // Load platform texture
    sf::Texture platformTexture;
    if (!platformTexture.loadFromFile("platform.png")) {
        // Handle error
    }

    // Create platform sprites
    sf::Sprite platform1(platformTexture);
    platform1.setPosition(0, 500);

    sf::Sprite platform2(platformTexture);
    platform2.setPosition(200, 400);

    sf::Sprite platform3(platformTexture);
    platform3.setPosition(400, 300);

    // Main game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Movement handling
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            mario.move(-5, 0); // Move Mario left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            mario.move(5, 0); // Move Mario right
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            // Jumping logic here
        }

        // Clear the window
        window.clear();

        // Draw platforms
        window.draw(platform1);
        window.draw(platform2);
        window.draw(platform3);

        // Draw Mario
        window.draw(mario);

        // Display everything
        window.display();
    }

    return 0;
}
