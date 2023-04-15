#include <SFML/Graphics.hpp>
#include <cstdlib> // pour rand() et srand()
#include <ctime> // pour time()


class Food{
    private:
    sf::Texture foodTexture;
    sf::Sprite food;

    public:
    Food();
    Food(const sf::Vector2u& window,  const sf::Vector2f& board);
    void generatePos(const sf::Vector2u& window,  const sf::Vector2f& board);
    sf::Vector2f getFoodPos() const;
    sf::Sprite getFood() const;
};