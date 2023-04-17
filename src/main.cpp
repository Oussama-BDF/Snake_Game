#include <SFML/Graphics.hpp>
#include "GameLogic.hpp"

int main(){

    // Créer une fenêtre de x*y pixels
    sf::RenderWindow window(sf::VideoMode(816, 624), "Snake Game");

    GameLogic game1(window.getSize());
    game1.play(window);
    
    return 0;
}