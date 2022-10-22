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
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML window");
    // Load a sprite to display
    // sf::Texture texture;
    // if (!texture.loadFromFile("resources/textures/board.jpeg"))
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
    Board board(&window);

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
