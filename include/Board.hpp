#include <SFML/Graphics.hpp>



class Board{
    private:
    // le plateau du jeu
    sf::RectangleShape board; 

    public:
    Board();

    // "window" -> "taille-fenêtre" : pour spécifier la position du plateau par rapport la fenêtre
    Board(const sf::Vector2u& window);

    // Récupérer la position du plateau par rapport la fenêtre
    sf::Vector2f getBoardPos() const;

     // Récupérer la taille du plateau
    sf::Vector2f getBoardSize() const;

    // Récupérer l'objet plateau
    sf::RectangleShape getBoard()const; 
};