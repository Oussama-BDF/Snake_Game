#include "GameMenu.hpp"


GameMenu::GameMenu(const sf::Vector2u& window) : text1("Start", this->font, 60), text2("Exit!", this->font, 60)
{
    this->font.loadFromFile("police.ttf");
    this->text2.setPosition(window.x/2 - this->text2.getGlobalBounds().width/2 , window.y/2 - this->text2.getGlobalBounds().height/2 + 60);
    this->text1.setPosition(window.x/2 - this->text1.getGlobalBounds().width/2 , window.y/2 - this->text1.getGlobalBounds().height/2 - 60);
    this->textRect1 = this->text1.getGlobalBounds();
    this->textRect2 = this->text2.getGlobalBounds();
    this->isClicked1=false;
}


void GameMenu::draw1(sf::RenderWindow& window) 
{
    window.draw(this->text1);
}


void GameMenu::draw2(sf::RenderWindow& window) 
{
    window.draw(this->text2);
}


bool GameMenu::checkClicked1(sf::RenderWindow& window)
{
    if (this->textRect1.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->text1.setFillColor(sf::Color(89,89,88));
            this->isClicked1=true;
            return false;
        }
    }
    
    if (this->isClicked1==true){
        this->text1.setFillColor(sf::Color::White);
        this->isClicked1=false;
        return true;
    }
    return false;
    

}


bool GameMenu::checkClicked2(sf::RenderWindow& window)
{
    if (this->textRect2.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->text2.setFillColor(sf::Color(89,89,88));
            this->isClicked2=true;
            return false;
        }
    }
    
    if (this->isClicked2==true){
        this->text2.setFillColor(sf::Color::White);
        this->isClicked2=false;
        return true;
    }
    return false;
}


bool GameMenu::displayMenu(sf::RenderWindow& window)
{
    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        this->draw1(window);
        this->draw2(window);

        if (this->checkClicked1(window)) {
            // Text1 a été cliqué
            return true;
        }

        if (this->checkClicked2(window)) {
            // Text2 a été cliqué
            break;
        }

        window.display();
    }    
    return false;
}