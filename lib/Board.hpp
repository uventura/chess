#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <array>
#include <iostream>

class Board
{
    private:
        sf::RenderWindow* m_window;
        uint32_t m_house_size;
        std::array<uint8_t, 3> m_white;
        std::array<uint8_t, 3> m_black;
        std::array<std::array<bool, 8>, 8> m_house_color;
        sf::Clock m_clock;

        sf::Event m_event;

        sf::RectangleShape getPieceHouse(
            sf::Color color,
            float pos_x,
            float pos_y
        );
        void displayBoard();
        void eventBoard();
    public:
        Board(
            sf::RenderWindow* window,
            uint32_t house_size = 50,
            std::array<uint8_t, 3> white_house = {255, 255, 255},
            std::array<uint8_t, 3> black_house = {0, 0, 0}
        );

        void display();
};
