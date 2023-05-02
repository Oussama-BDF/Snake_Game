#include "GameLogic.hpp"



GameLogic::GameLogic(const sf::Vector2u& window) : snake(window), board(window), food(window)
{
    this->gameOver=false;
    this->score.setString("Score: 0");
    this->score.setCharacterSize(40);
}


bool GameLogic::getGameOver(){return this->gameOver;}


void GameLogic::logic(const sf::Vector2u& window)
{
    this->snake.input();

    this->snake.shift();

    // Tester la collision entre le serpent et la nourriture
    if (this->snake.getHeadPos().x == this->food.getFoodPos().x && this->snake.getHeadPos().y == this->food.getFoodPos().y)
    { 
        this->food.generatePos(window, this->board.getBoardPos());

        this->snake.addSegment();
            
        // Incrémenter le score 
        int s = stoi(string(this->score.getString().substring(7))) +1;
        this->score.setString(this->score.getString().substring(0,7) + to_string(s));
    }

    // Modifier la position de la tête à chaque itération,
	this->snake.changePos();

    // Tester la collision du serpent avec le plateau
    if (this->snake.getHeadPos().x < this->board.getBoardPos().x || this->snake.getHeadPos().y < this->board.getBoardPos().y || this->snake.getHeadPos().x == this->board.getBoardPos().x+this->board.getBoardSize().x || this->snake.getHeadPos().y == this->board.getBoardPos().y+this->board.getBoardSize().y)
    {
        this->gameOver=true;
    }

}


void GameLogic::draw(sf::RenderWindow& window)
{
    window.draw(this->board.getBoard());
    window.draw(this->food.getFood());
    window.draw(this->snake.getHead());
     window.draw(this->score);
    for (int l=0; l<this->snake.getTailLength()+2; l++) // +2 pour afficher les segments 1 et 2
    {
        window.draw(this->snake.getSegment(l));
    }
}


bool GameLogic::displayMenu(sf::RenderWindow& window)
{
    return this->menu.displayMenu(window);
}


void GameLogic::play(sf::RenderWindow& window)
{
    //On a besoin cette police pour tous les textes
    sf::Font font;
    font.loadFromFile("police.ttf");

    this->score.setFont(font);
    this->score.setPosition(window.getSize().x/2 - this->score.getGlobalBounds().width/2,20);

    //on aura besoin cette variable pour ralentir le mouvement de la boucle principale (8 images par second)
    sf::Time timePerFrame = sf::seconds(1.f / 8.f);

    // Boucle principale du jeu
    while (window.isOpen())
    {
        // Gérer les événements de la fenêtre
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Effacer l'écran
        window.clear(sf::Color::Black);

        // Dessiner le jeu
        this->draw(window);

        // Afficher l'écran
        window.display();

        // Appliquer la logique du jeu
        this->logic(window.getSize());

        // Afficher "Game Over!!" en 4 seconds, et sortir de la boucle si l'utilisateur perd
        if (this->getGameOver()==true)
        {
            sf::Text text("Game Over!!",font,60);
            text.setPosition(window.getSize().x/2 - text.getGlobalBounds().width/2 , window.getSize().y/2 - text.getGlobalBounds().height/2);
            
            for(int j=0; j<32 ; j++)
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                window.clear();
                this->draw(window);
                window.draw(text);
                window.display();
                sf::sleep(timePerFrame);
            }
            break;
        }

        // Ralentir le mouvement de la boucle (8 images/itérations par second)
        sf::sleep(timePerFrame);

    }
}


