#include "Board.hpp"

Board::Board(){}

Board::Board(const sf::Vector2u& window) : board(sf::Vector2f(720, 400))
{
    this->board.setFillColor(sf::Color::Green);
    this->board.setPosition(window.x/2 - this->board.getSize().x/2, window.y/2 - this->board.getSize().y/2);
    this->board.setOutlineThickness(5);
    this->board.setOutlineColor(sf::Color::Red);
}

sf::Vector2f Board::getBoardPos() const{ return this->board.getPosition(); }

sf::Vector2f Board::getBoardSize() const{ return this->board.getSize(); }

sf::RectangleShape Board::getBoard() const{ return this->board; }