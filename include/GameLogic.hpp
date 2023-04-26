#include <SFML/Graphics.hpp>
#include "Food.hpp"
#include "Snake.hpp"
#include "Board.hpp"
#include "GameMenu.hpp"



class GameLogic{
    private:
    GameMenu menu;
    Snake snake;
    Food food;
    Board board;
    bool gameOver;
    int score;


    public:
    GameLogic(){}
    GameLogic(const sf::Vector2u& window);
    
    bool getGameOver();

    // la logique du jeu
    void logic(const sf::Vector2u& window);

    // Dessiner tous les objets
    void draw(sf::RenderWindow& window);

    // Appeler la fonction "displayMenu()" de la classe "GameMenu" et retourner sa valeur (true:start   false:exit)
    bool displayMenu(sf::RenderWindow& window);

    // La boucle principale du jeu
    void play(sf::RenderWindow& window);

};