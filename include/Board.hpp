#include <SFML/Graphics.hpp>



class Board{
    private:
    // le plateau du jeu
    sf::RectangleShape board; 

    public:
    Board();

    // "window" -> "taille-fenêtre" : pour spécifier la position du plateau par rapport la fenêtre
    Board(const sf::Vector2u& window);

    // Retourner la position du plateau par rapport la fenêtre
    sf::Vector2f getBoardPos() const;

     // Retourner la taille du plateau
    sf::Vector2f getBoardSize() const;

    // Retourner l'objet plateau
    sf::RectangleShape getBoard()const; 
};