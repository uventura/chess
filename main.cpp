#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <vector>

#include "lib/Board.hpp"
#include "lib/Piece.hpp"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(400, 400), "Chess");

    // Load a sprite to display
    sf::Texture pieces_texture;
    pieces_texture.setSmooth(true);
    if (!pieces_texture.loadFromFile("resources/textures/pieces.png"))
        return EXIT_FAILURE;
    sf::Sprite pieces_sprite(pieces_texture);

    sf::Event event;

    // Board
    Board board(
        &window,
        50,
        {86,61,45},
        {219,200,188}
    );

    // Pieces
    std::vector<Piece> pieces;

    for(int x = 0; x < 6; ++x)
    {
        for(int y = 0; y < 6; ++y)
        {
            pieces_sprite.setScale(sf::Vector2f(0.25f, 0.25f));
            pieces_sprite.setTextureRect(sf::IntRect(200 * y, 200 * x, 200, 200));

            Piece current_piece(
                pieces_sprite,
                window
            );

            pieces.push_back(current_piece);
        }
    }

    while (window.isOpen())
    {
        // Process events
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
        pieces[2].display();

        if (event.type == sf::Event::Resized)
        {
            // update the view to the new size of the window
            sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
            window.setView(sf::View(visibleArea));
        }

        // Draw the sprite
        // 
        // window.draw(sprite);
        // Draw the string
        // window.draw(text);
        // Update the window
        window.display();
        // window.setView(window.getView());
        // std::cout << view.width << "\n";
    }

    return EXIT_SUCCESS;
}
