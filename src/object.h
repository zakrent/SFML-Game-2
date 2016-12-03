#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Object{
public: //placeholder
    bool isSolid;
    bool isStatic;
    int mass;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::RectangleShape sprite;
public:
    Object();
    Object(float _x, float _y,float _xSize, float _ySize, bool _isSolid);
    Object(float _x, float _y,float _xSize, float _ySize,float _xSpeed, float _ySpeed, int _mass, bool _isSolid);

    void update();
    void checkCollision(Object* &colCandidate);
};
