#include <SFML/Graphics.hpp>
#include <vector>

    
enum direction{ UP,DOWN,RIGHT,LEFT };

class Snake{
    private:
    sf::Texture headRight;
    sf::Texture headLeft;
    sf::Texture headUp;
    sf::Texture headDown;
    sf::Sprite head;
    sf::CircleShape *tail[20]; //Segments
    direction dir;
    int tailLength;

    public:
    Snake();
    Snake(const sf::Vector2u& window);
    direction getDir() const;
    void setDir(direction);
    int getTailLength() const;
    void shift();
    sf::Vector2f getHeadPos() const;
    void addSegment();
    void input();
    void ModifyPos();
    sf::Sprite getHead() const;
    sf::CircleShape getSegment(int i) const;
};