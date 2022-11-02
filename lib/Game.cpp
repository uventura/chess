#include "lib/Game.hpp"

Game::Game(sf::RenderWindow& window):
m_window(window)
{
    m_board = std::unique_ptr<Board>(new Board(window, 50, {86,61,45}, {219,200,188}));

    m_pieces_texture.setSmooth(true);
    if (!m_pieces_texture.loadFromFile("resources/textures/pieces.png"))
    {
        std::cout << "[ERROR] Failed to load Pieces.\n";
        return;
    }

    m_pieces_sprite = sf::Sprite(m_pieces_texture);

    loadPieces();
}

void Game::display()
{
    m_board->display();
    displayPieces();
}

void Game::update(sf::Event& event)
{
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(pieces[i][j] != nullptr)
            {
                std::array<int, 2> positions = pieces[i][j]->update(event);

                if(positions[0] != -1)
                {
                    pieces[i][j]->setPosition(positions[0], positions[1]);

                    int x = positions[0] / 50;
                    int y = positions[1] / 50;

                    if((pieces[y][x] != nullptr
                    && pieces[y][x]->getGroup() != pieces[i][j]->getGroup())
                    || (pieces[y][x] == nullptr))
                    {
                        pieces[y][x] = std::make_shared<Piece>(*pieces[i][j]);
                        pieces[i][j] = nullptr;
                    }
                    else
                    {
                        pieces[i][j]->resetPosition();
                    }
                }
            }
        }
    }
}

void Game::loadPieces()
{
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
            pieces[i][j] = nullptr;
    }

    enum pieces_enum{KING, QUEEN, BISHOP, KNIGHT, TOWER, PAWN};
    int first_line[8] = {
        pieces_enum::TOWER,
        pieces_enum::KNIGHT,
        pieces_enum::BISHOP,
        pieces_enum::QUEEN,
        pieces_enum::KING,
        pieces_enum::BISHOP,
        pieces_enum::KNIGHT,
        pieces_enum::TOWER
    };

    std::string first_line_names[8] = {
        "tower",
        "knight",
        "bishop",
        "queen",
        "king",
        "bishop",
        "knight",
        "tower"
    };

    for(int i = 0; i < 8; ++i)
    {
        loadPiece(6, i, pieces_enum::PAWN * 200, 0, "pawn", "white");
        loadPiece(1, i, pieces_enum::PAWN * 200, 200, "pawn", "black");

        loadPiece(7, i, first_line[i] * 200, 0, first_line_names[i], "white");
        loadPiece(0, i, first_line[i] * 200, 200, first_line_names[i], "black");
    }
}

void Game::loadPiece(
    int line,
    int row,
    int map_x,
    int map_y,
    std::string name,
    std::string group
)
{
    m_pieces_sprite.setScale(sf::Vector2f(0.25f, 0.25f));
    m_pieces_sprite.setTextureRect(sf::IntRect(map_x, map_y, 200, 200));

    pieces[line][row] = std::shared_ptr<Piece>(
        new Piece(m_pieces_sprite, m_window, row * 50, line * 50, name, group)
    );
}

void Game::displayPieces()
{
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(pieces[i][j] != nullptr)
                pieces[i][j]->display();
        }
    }
}
