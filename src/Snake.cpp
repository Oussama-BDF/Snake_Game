#include "Snake.hpp"


Snake::Snake(){}


Snake::Snake(const sf::Vector2u& window)
{
    // Télécharger les images du serpent, et le mettre dans le centre de la fenêtre
    this->headRight.loadFromFile("../Images/headRight.png");
    this->headLeft.loadFromFile("../Images/headLeft.png");
    this->headUp.loadFromFile("../Images/headUp.png");
    this->headDown.loadFromFile("../Images/headDown.png");
    this->head.setTexture(headRight);
    this->head.setPosition(window.x/2 - this->head.getGlobalBounds().width/2, window.y/2 - this->head.getGlobalBounds().height/2);
    //Initialiser la direction à droit, et la taille des segment à 0
    this->dir=RIGHT;
    this->tailLength=0;

    // Initialiser le tableau "tail" par 2 objets 
    for (int i=0; i<=1; i++)
    {
        this->tail[i] = new sf::CircleShape(8.f);
        this->tail[i]->setPosition(this->head.getPosition().x-16*(i+1) , this->head.getPosition().y);
        this->tail[i]->setFillColor(sf::Color(36,126,244));
    }

}


direction Snake::getDir() const{  return this->dir;  }


void Snake::setDir(direction dir){ this->dir=dir; }


int Snake::getTailLength() const{ return this->tailLength; }


sf::Vector2f Snake::getHeadPos() const{ return this->head.getPosition(); }


sf::Sprite Snake::getHead() const { return this->head; }


sf::CircleShape Snake::getSegment(int i) const { return *this->tail[i]; }


void Snake::input()
{
    // Modifier les valeur de "dir" et "head" selon la flèche sur laquelle l'utilisateur appuie.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->dir!=LEFT )
    {
        this->dir = RIGHT;
        this->head.setTexture(headRight);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->dir!=RIGHT)
    {
        this->dir = LEFT;
        this->head.setTexture(headLeft);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->dir!=DOWN)
    {
        this->dir = UP;
        this->head.setTexture(headUp);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)  && this->dir!=UP)
    {
        this->dir = DOWN;
        this->head.setTexture(headDown);
    }
}


void Snake::shift()
{
    for (int i=this->tailLength; i>=0; i--)
    {
        this->tail[i+1]->setPosition(this->tail[i]->getPosition());
    }
    // le segment 1 prend la position de la tête
    this->tail[0]->setPosition(this->head.getPosition());
}


void Snake::addSegment()
{
    // Incrémentez la taille du serpent 
    this->tailLength++;
    // Créer un nouveau segment du serpent à la fin du tableau
    this->tail[tailLength+1] = new sf::CircleShape(8.f); // tailLength+1 -> parce que le tableau dèja initialisé par 2 objets
    this->tail[tailLength+1]->setFillColor(sf::Color(36,126,244));
    this->tail[tailLength+1]->setPosition(this->head.getPosition());
}


void Snake::changePos()
{
    // le serpent avance de 16 pixels
	switch(this->dir)
	{
	case UP: this->head.setPosition(this->head.getPosition().x,this->head.getPosition().y-16); break;
	case DOWN: this->head.setPosition(this->head.getPosition().x,this->head.getPosition().y+16); break;
	case RIGHT: this->head.setPosition(this->head.getPosition().x+16,this->head.getPosition().y); break;
	case LEFT: this->head.setPosition(this->head.getPosition().x-16,this->head.getPosition().y); break;
	}
}