#include "GameMenu.hpp"


bool GameMenu::checkClicked(sf::RenderWindow& window, sf::FloatRect& textRect, sf::Text& text, bool& isClicked)
{
    if (textRect.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            text.setFillColor(sf::Color(140,140,140));
            isClicked=true;
            return false;
        }
    }
    
    if (isClicked==true){
        text.setFillColor(sf::Color::White);
        isClicked=false;
        return true;
    }
    return false;
    

}


bool GameMenu::displayMenu(sf::RenderWindow& window)
{
    // La police du text
    sf::Font font;
    font.loadFromFile("../Police/police.ttf");

    // le titre du jeu
    sf::Text text("Snake Game", font, 70);
    text.setPosition(window.getSize().x/2 - text.getGlobalBounds().width/2 , 30 );

    // Le text1 start (Bouton1)
    sf::Text start("Start", font, 50);
    start.setPosition(window.getSize().x/2 - start.getGlobalBounds().width/2 , window.getSize().y/2 - start.getGlobalBounds().height/2 - 50);
    sf::FloatRect textRect1=start.getGlobalBounds();

    // Le text2 exit (Bouton2)
    sf::Text exit("Exit!", font, 50);
    exit.setPosition(window.getSize().x/2 - exit.getGlobalBounds().width/2 , window.getSize().y/2 - exit.getGlobalBounds().height/2 + 50);
    sf::FloatRect textRect2=exit.getGlobalBounds();

    bool isClicked1=false, isClicked2=false;

    // Les bordures
    sf::RectangleShape border(sf::Vector2f(window.getSize().x -40, window.getSize().y -40));
    border.setPosition(window.getSize().x/2 - border.getSize().x/2, window.getSize().y/2 - border.getSize().y/2); 
    border.setOutlineThickness(3);
    border.setOutlineColor(sf::Color::White);
    border.setFillColor(sf::Color::Transparent);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(48,48,48));

        window.draw(start);
        window.draw(exit);
        window.draw(text);
        window.draw(border);

        if (this->checkClicked(window,textRect1, start, isClicked1)) {
            // Text1 a été cliqué
            return true;
        }

        if (this->checkClicked(window,textRect2, exit, isClicked2)) {
            // Text2 a été cliqué
            break;
        }

        window.display();
    }    
    return false;
}