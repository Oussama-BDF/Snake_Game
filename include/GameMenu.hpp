#include <SFML/Graphics.hpp>

// une class pour le menu du jeu (on va créer des boutons)
class GameMenu
{
    private:
    sf::Font font;
    sf::Text text1;
    sf::FloatRect textRect1;
    sf::Text text2;
    sf::FloatRect textRect2;
    bool isClicked1;
    bool isClicked2;

    public:
    GameMenu(){}
    GameMenu(const sf::Vector2u& window);

    // Dessiner le texte1(bouton1)
    void draw1(sf::RenderWindow& window);
    // Dessiner le texte2(bouton2)
    void draw2(sf::RenderWindow& window);
    // tester si le text1(bouton1) à été cliquez
    bool checkClicked1(sf::RenderWindow& window);
    // tester si le text2(bouton2) à été cliquez
    bool checkClicked2(sf::RenderWindow& window);


};