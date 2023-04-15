#include <SFML/Graphics.hpp>
#include "GameLogic.hpp"

int main(){

    sf::RenderWindow window(sf::VideoMode(816, 624), "Snake Game");
    GameLogic game1(window.getSize());
    game1.startPlay(window);
    return 0;
}