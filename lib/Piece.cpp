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

void Piece::update(sf::Event& event)
{
    // m_event = event;

    if(event.type == sf::Event::MouseButtonPressed
    && event.mouseButton.button == sf::Mouse::Left
    && event.mouseButton.x >= pos_x && event.mouseButton.x < pos_x + 50
    && event.mouseButton.y >= pos_y && event.mouseButton.y < pos_y + 50
    )
    {
        is_moving = true;
    }
    if(event.type == sf::Event::MouseButtonReleased)
    {
        pos_x = old_x;
        pos_y = old_y;

        is_moving = false;
    }

    if(is_moving)
    {
        sf::Vector2i position = sf::Mouse::getPosition(m_window);
        pos_x = position.x;
        pos_y = position.y;

        int interval_x = (int)(pos_x/100) * 100;
        int interval_y = (int)(pos_y/100) * 100;
        old_x = (pos_x < interval_x + 50 ? interval_x : interval_x + 50);
        old_y = (pos_y < interval_y + 50 ? interval_y : interval_y + 50);
    }
}

void Piece::move()
{
    m_piece.setPosition(pos_x, pos_y);

    if(is_moving)
        m_piece.setOrigin(100, 100);
    else
        m_piece.setOrigin(0, 0);
}
