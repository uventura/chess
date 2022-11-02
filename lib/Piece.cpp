#include "lib/Piece.hpp"

Piece::Piece(
    sf::Sprite piece,
    sf::RenderWindow& window,
    int x,
    int y,
    std::string name,
    std::string group
):
m_piece(piece),
m_window(window),
pos_x(x),
pos_y(y),
m_name(name),
m_group(group),
is_moving(false)
{
    move();
    old_x = x;
    old_y = y;
}

void Piece::display()
{
    move();
    m_window.draw(m_piece);
}

std::array<int, 2> Piece::update(sf::Event& event)
{
    if(event.type == sf::Event::MouseButtonPressed
    && event.mouseButton.button == sf::Mouse::Left
    && event.mouseButton.x >= pos_x && event.mouseButton.x < pos_x + 50
    && event.mouseButton.y >= pos_y && event.mouseButton.y < pos_y + 50
    )
    {
        std::array<int, 2> positions = normalize(pos_x, pos_y);
        old_x = positions[0];
        old_y = positions[1];

        is_moving = true;
    }
    else if(event.type == sf::Event::MouseButtonReleased && is_moving)
    {
        is_moving = false;
        return normalize(pos_x, pos_y);
    }

    if(is_moving)
    {
        sf::Vector2i position = sf::Mouse::getPosition(m_window);
        pos_x = position.x;
        pos_y = position.y;
    }

    return {-1, -1};
}

void Piece::move()
{
    m_piece.setPosition(pos_x, pos_y);

    if(is_moving)
        m_piece.setOrigin(100, 100);
    else
        m_piece.setOrigin(0, 0);
}

std::array<int, 2> Piece::normalize(int x, int y)
{
    int interval_x = (int)(x/100) * 100;
    int interval_y = (int)(y/100) * 100;
    int current_x = (x < interval_x + 50 ? interval_x : interval_x + 50);
    int current_y = (y < interval_y + 50 ? interval_y : interval_y + 50);

    return {current_x, current_y};
}
