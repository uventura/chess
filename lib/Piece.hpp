#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <array>
#include <string>
#include <iostream>

class Piece
{
    private:
        sf::Sprite m_piece;
        sf::RenderWindow& m_window;
        int pos_x, pos_y;

        std::string m_name;
        std::string m_group;

        int old_x, old_y;

        // sf::Event& m_event;
    public:
        Piece(
            sf::Sprite piece,
            sf::RenderWindow& window,
            int x = 0,
            int y = 0,
            std::string name = "none",
            std::string group = "none"
        );

        void display();
        std::array<int, 2> update(sf::Event& event);
        void move();
        inline void setPosition(int x, int y){pos_x = x;pos_y = y;};

        bool is_moving;
};
