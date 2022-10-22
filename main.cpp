#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
// #include <SFML/Color.hpp>

#include <iostream>

#include "lib/Board.hpp"

// struct pieceHouse{
//     public:
//         pieceHouse(color);
// }

// sf::RectangleShape getPieceHouse(sf::Color color, float pos_x, float pos_y)
// {
//     sf::RectangleShape rectangle;
//     rectangle.setSize(sf::Vector2f(50, 50));
//     rectangle.setFillColor(color);
//     rectangle.setOutlineThickness(0);
//     rectangle.setPosition(pos_x, pos_y);

//     return rectangle;
// }

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(400, 400), "Chess");
    // Load a sprite to display
    // sf::Texture texture;
    // texture.setSmooth(true);
    // if (!texture.loadFromFile("resources/textures/pieces.png"))
    //     return EXIT_FAILURE;
    // sf::Sprite sprite(texture);
    // // Create a graphical text to display
    // sf::Font font;
    // if (!font.loadFromFile("arial.ttf"))
    //     return EXIT_FAILURE;
    // sf::Text text("Hello SFML", font, 50);

    // Play the music
    // music.play();
    // Start the game loop

    sf::Event event;
    Board board(
        &window,
        50,
        {86,61,45},
        {219,200,188}
    );

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // if (event.type == sf::Event::MouseButtonPressed)
        // {
        //     if (event.mouseButton.button == sf::Mouse::Right)
        //     {
        //         std::cout << "the right button was pressed" << std::endl;
        //         std::cout << "mouse x: " << event.mouseButton.x << std::endl;
        //         std::cout << "mouse y: " << event.mouseButton.y << std::endl;
        //     }
        // }

        // Clear screen
        window.clear();

        // Render things
        board.display();

        if (event.type == sf::Event::Resized)
        {
            // update the view to the new size of the window
            sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
            window.setView(sf::View(visibleArea));
        }

        // Draw the sprite
        // sprite.setScale(sf::Vector2f(0.25f, 0.25f));
        // sprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
        // window.draw(sprite);
        // Draw the string
        // window.draw(text);
        // Update the window
        window.display();
        // window.setView(window.getView());

        auto view = window.getViewport(window.getView());
        // std::cout << view.width << "\n";
    }

    return EXIT_SUCCESS;
}
