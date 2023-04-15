#include <SFML/Graphics.hpp>



class Board{
    private:
    sf::RectangleShape board;

    public:
    Board();
    Board(const sf::Vector2u& window);
    sf::Vector2f getBoardPos() const;
    sf::Vector2f getBoardSize() const;
    sf::RectangleShape getBoard()const;
};