#include <SFML/Graphics.hpp>

// une class pour le menu du jeu (on va créer des boutons)
class GameMenu
{
    public:
    // Retourner true si le text(bouton) a été cliqué
    bool checkClicked(sf::RenderWindow& window,  sf::FloatRect& textRect, sf::Text& text, bool& isClicked);
    // Afficher le menu
    bool displayMenu(sf::RenderWindow& window);
};