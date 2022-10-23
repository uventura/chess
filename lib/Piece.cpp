#include "lib/Piece.hpp"

Piece::Piece(
    sf::Sprite piece,
    sf::RenderWindow& window,
    int x,
    int y,
    std::string name,
    std::string group
):
m_piece(piece), m_window(window), pos_x(x), pos_y(y), m_name(name), m_group(group)
{
    move(x, y);
}

void Piece::display()
{
    m_window.draw(m_piece);
}

void Piece::move(int pos_x, int pos_y)
{
    m_piece.move(pos_x, pos_y);
}
