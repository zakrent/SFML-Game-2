#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Object{
public: //placeholder
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::RectangleShape sprite;
public:
    Object(float _x, float _y,float _xSize, float _ySize, float _xSpeed, float _ySpeed);
    void update();
    void checkCollision(Object* &colCandidate);
};
