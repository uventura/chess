#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "lib/Board.hpp"
#include "lib/Piece.hpp"
#include "lib/Game.hpp"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(400, 400), "Chess");
    sf::Event event;

    Game game(window);

    while (window.isOpen())
    {
        // Process events
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        game.update(event);

        // Clear screen
        window.clear();

        // Render things
        game.display();

        if (event.type == sf::Event::Resized)
        {
            // update the view to the new size of the window
            sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
            window.setView(sf::View(visibleArea));
        }

        window.display();
    }

    // delete(m_board);
    return EXIT_SUCCESS;
}
