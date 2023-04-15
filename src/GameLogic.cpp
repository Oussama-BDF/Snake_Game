#include "GameLogic.hpp"



GameLogic::GameLogic(const sf::Vector2u& window) : snake(window), board(window), food(window,this->board.getBoardPos())
{
    this->gameOver=false;
    this->score=0;
}

bool GameLogic::getGameOver(){return this->gameOver;}

void GameLogic::logic(const sf::Vector2u& window)
{
    this->snake.input();

    // Chaque segment du serpent prend la position du segment suivant
    this->snake.shift();

    // Tester la collision entre le serpent et la nourriture
    if (this->snake.getHeadPos().x == this->food.getFoodPos().x && this->snake.getHeadPos().y == this->food.getFoodPos().y)
    { 
        // Générer une position aléatoirement pour la nourriture
        this->food.generatePos(window, this->board.getBoardPos());
            
        // Incrémentez le score
        this->score++;
	    this->snake.addSegment();
    }

    // Modifier la position du cercle à chaque itération,
	this->snake.ModifyPos();

    // Tester la collision du serpent avec le plateau
    if (this->snake.getHeadPos().x < this->board.getBoardPos().x || this->snake.getHeadPos().y < this->board.getBoardPos().y || this->snake.getHeadPos().x == this->board.getBoardPos().x+this->board.getBoardSize().x || this->snake.getHeadPos().y == this->board.getBoardPos().y+this->board.getBoardSize().y)
    {
        this->gameOver=true;
    }

}

void GameLogic::drawing(sf::RenderWindow& window)
{
    window.draw(this->board.getBoard());
    window.draw(this->food.getFood());
    window.draw(this->snake.getHead());
    for (int l=0; l<this->snake.getTailLength()+2; l++) // +1 pour afficher le segment 2
    {
        window.draw(this->snake.getSegment(l));
    }
}

void GameLogic::startPlay(sf::RenderWindow& window)
{
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

        // Dessiner le plateau de jeu
        this->drawing(window);

        // Afficher l'écran
        window.display();



        this->logic(window.getSize());
        if (this->getGameOver()==true)  window.close();

        // Ralentir le mouvement de la boucle (9 image par second)
        sf::sleep(timePerFrame);

    }
}


