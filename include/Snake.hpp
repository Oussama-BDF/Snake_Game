#include <SFML/Graphics.hpp>
#include <vector>

// la direction du serpent
enum direction{ UP,DOWN,RIGHT,LEFT };

class Snake{
    private:
    // La tête du serpent
    sf::Texture headRight;
    sf::Texture headLeft;
    sf::Texture headUp;
    sf::Texture headDown;
    sf::Sprite head;

    // Un tableau pour stocker les segments du serpent
    sf::CircleShape *tail[20];

    direction dir;
    int tailLength;

    public:
    Snake();
    
    // "window" -> "taille-fenêtre" : pour spécifier la position du serpent par rapport la fenêtre
    Snake(const sf::Vector2u& window);

    // Getters & Setters
    direction getDir() const;
    int getTailLength() const;
    void setDir(direction);

    // Retourner l'objet head (de type sprite)
    sf::Sprite getHead() const;

    // Retourner le segment de l'index i (de type CircleShape)
    sf::CircleShape getSegment(int i) const;

    //Retourner la position de la tête (de type Vector2f)
    sf::Vector2f getHeadPos() const;

    // Chaque segment du serpent prend la position du segment suivant
    void shift();

    // Créer un nouveau segment dans le tableau "tail", au cas où le serpent mange la pomme
    void addSegment();

    // Détecter la flèche de la clavier sur laquelle l'utilisateur appuie.
    void input();

    // Changer la position de la tête selon la valeur de la variable dir (direction)
    void changePos();
};