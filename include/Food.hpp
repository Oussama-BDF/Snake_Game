#include <SFML/Graphics.hpp>
#include <cstdlib> // pour rand() et srand()
#include <ctime> // pour time()


class Food{
    private:
    sf::Texture foodTexture;
    sf::Sprite food;

    public:
    Food();

    // "window" -> "taille-fenêtre" : pour spécifier la position de la nourriture par rapport la fenêtre
    Food(const sf::Vector2u& window);

    // Retourner la position de la nourriture
    sf::Vector2f getFoodPos() const;

    // Retourner l'objet "food"
    sf::Sprite getFood() const;

    // Générer une position aléatoire pour la nourriture
    void generatePos(const sf::Vector2u& window,  const sf::Vector2f& board);

};