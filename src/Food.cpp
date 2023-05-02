#include "Food.hpp"

Food::Food(){}


Food::Food(const sf::Vector2u& window)
{
    // Initialiser la génération aléatoire avec la valeur de temps actuelle
    srand(time(NULL));

    // Télécharger l'images de la nourriture, et la mettre dans le centre de la fenêtre
    this->foodTexture.loadFromFile("Images/food.png");
    this->food.setTexture(this->foodTexture);
    food.setPosition((window.x/2 - this->food.getGlobalBounds().width/2) -16, (window.y/2 - this->food.getGlobalBounds().height/2)+32);
}


sf::Vector2f Food::getFoodPos() const{ return this->food.getPosition(); }


sf::Sprite Food::getFood() const{ return this->food; }


void Food::generatePos(const sf::Vector2u& window,  const sf::Vector2f& board)
{
    // Déclarer une variable pour stocker la position aléatoire de la nourriture
    sf::Vector2f foodPosition;
    // Générer une position x aléatoire entre 0 et la largeur du rectangle (pas de la fenêtre)
    int k = (window.x - board.x*2)/16;
    foodPosition.x = (rand() % k)*16 + board.x;
    // Générer une position y aléatoire entre 0 et la hauteur du rectangle (pas de la fenêtre)
    k = (window.y - board.y*2)/16;
    foodPosition.y = (rand() % k)*16 + board.y;
    food.setPosition( foodPosition );
}

