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
    displayBoard();
    // eventBoard();
}

sf::RectangleShape Board::getPieceHouse(sf::Color color, float pos_x, float pos_y)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(m_house_size, m_house_size));
    rectangle.setFillColor(color);
    rectangle.setPosition(pos_x, pos_y);

    return rectangle;
}

void Board::displayBoard()
{
    bool invert = true;
    for(int pos_x = 0; pos_x < 8; ++pos_x)
    {
        for(int pos_y = 0; pos_y < 8; ++pos_y)
        {
            std::array<uint8_t, 3> colors;
            colors = invert?m_white:m_black;
            invert = !invert;

            sf::Color color(colors[0], colors[1], colors[2]);
            m_window->draw(
                getPieceHouse(
                    color,
                    pos_x * m_house_size,
                    pos_y * m_house_size
                ));
        }
        invert = !invert;
    }
}

void Board::eventBoard()
{
    m_window->pollEvent(m_event);
    sf::Time elapsed = m_clock.getElapsedTime();

    if (m_event.type == sf::Event::MouseButtonPressed
    &&  m_event.mouseButton.button == sf::Mouse::Left
    && (m_event.mouseButton.x >= 0 && (uint32_t)m_event.mouseButton.x < m_house_size * 8)
    && (m_event.mouseButton.y >= 0 && (uint32_t)m_event.mouseButton.y < m_house_size * 8)
    )
    {
        for(int x = 0; x < 8; ++x)
        {
            for(int y = 0; y < 8; ++y)
                m_house_color[x][y] = false;
        }
        m_house_color[(int)(m_event.mouseButton.x / 50)][(int)(m_event.mouseButton.y / 50)] = true;

        m_clock.restart();
    }
}
