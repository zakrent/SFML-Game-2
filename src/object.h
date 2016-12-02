#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Object{
public: //placeholder
    bool isSolid;
    sf::Vector2f prevPosition;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::RectangleShape sprite;
public:
    Object();
    Object(float _x, float _y,float _xSize, float _ySize,float _xSpeed, float _ySpeed, bool _isSolid);

    void update();
    void checkCollision(Object* &colCandidate);
};
