#include "lib/Board.hpp"

Board::Board(
    sf::RenderWindow* window,
    uint32_t house_size,
    std::array<uint8_t, 3> white_house,
    std::array<uint8_t, 3> black_house
)
{
    m_window = window;
    m_house_size = house_size;
    m_white = white_house;
    m_black = black_house;
}

void Board::display()
{
    bool invert = true;
    for(float pos_x = 0; pos_x < 8; ++pos_x)
    {
        for(float pos_y = 0; pos_y < 8; ++pos_y)
        {
            std::array<uint8_t, 3> colors;
            if(invert)
            {
                colors = m_white;
            }
            else
            {
                colors = m_black;
            }

            invert = !invert;

            sf::Color color(colors[0], colors[1], colors[2]);
            m_window->draw(getPieceHouse(color, pos_x * m_house_size, pos_y * m_house_size));
        }
        invert = !invert;
    }
}

sf::RectangleShape Board::getPieceHouse(sf::Color color, float pos_x, float pos_y)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(m_house_size, m_house_size));
    rectangle.setFillColor(color);
    rectangle.setOutlineThickness(0);
    rectangle.setPosition(pos_x, pos_y);

    return rectangle;
}
