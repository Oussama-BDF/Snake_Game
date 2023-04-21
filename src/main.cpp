#include <SFML/Graphics.hpp>
#include "GameLogic.hpp"

int main(){

    // Créer une fenêtre de x*y pixels
    sf::RenderWindow window(sf::VideoMode(816, 624), "Snake Game");

   GameLogic *game1 = new GameLogic(window.getSize());
    
    while (game1->displayMenu(window)==true)
    {
        game1->play(window);
        game1= new GameLogic(window.getSize());
    }
    
    return 0;
}