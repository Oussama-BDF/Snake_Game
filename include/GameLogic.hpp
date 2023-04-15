#include <SFML/Graphics.hpp>
#include "Food.hpp"
#include "Snake.hpp"
#include "Board.hpp"



class GameLogic{
    private:
    bool gameOver;
    Snake snake;
    Food food;
    Board board;
    int score;


    public:
    GameLogic(const sf::Vector2u& window);
    bool getGameOver();
    void logic(const sf::Vector2u& window);
    void drawing(sf::RenderWindow& window);
    void startPlay(sf::RenderWindow& window);


};