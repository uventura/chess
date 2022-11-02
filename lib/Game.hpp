#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

#include "lib/Board.hpp"
#include "lib/Piece.hpp"

class Game
{
    private:
        std::map<std::string, std::shared_ptr<Piece>> m_white_pieces;
        std::map<std::string, std::shared_ptr<Piece>> m_black_pieces;

        std::unique_ptr<Board> m_board;
        sf::Texture m_pieces_texture;
        std::unique_ptr<Piece> m_piece;

        // Board* m_board;
        sf::RenderWindow& m_window;
        sf::Sprite m_pieces_sprite;

        std::shared_ptr<Piece> pieces[8][8];

        void loadPieces();
        void loadPiece(
            int line,
            int row,
            int map_x,
            int map_y,
            std::string name,
            std::string group
        );
        void displayPieces();

        int counter = 0;

        int ux = -1, uy = -1, vx, vy;
    public:
        Game(sf::RenderWindow& window);
        void display();
        void update(sf::Event& event);
};
