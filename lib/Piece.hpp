#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <string>

class Piece
{
    private:
        sf::Sprite m_piece;
        sf::RenderWindow& m_window;
        int pos_x, pos_y;

        std::string m_name;

    public:
        Piece(
            sf::Sprite piece,
            sf::RenderWindow& window,
            int x = 0,
            int y = 0,
            std::string name = "none"
        );

        void display();
        void move(int pos_x, int pos_y);
};
