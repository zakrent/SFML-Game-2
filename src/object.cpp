#include "object.h"
#include <math.h>

Object::Object(float _x, float _y,float _xSize, float _ySize, float _xSpeed, float _ySpeed){
    position = {_x, _y};
    velocity = {_xSpeed, _ySpeed};
    sprite.setSize(sf::Vector2f{_xSize, _ySize});
}

void Object::update(){
    position += velocity;
    sprite.setPosition(position);
}

bool rangeIntersect(float min0,float max0,float min1,float max1){
    return max0 > min1 && min0 < max1;
}
void Object::checkCollision(Object* &colCandidate){
    bool collision =
    rangeIntersect(
        position.x, position.x+sprite.getSize().x,
        colCandidate->position.x, colCandidate->position.x+colCandidate->sprite.getSize().x)
    &&
    rangeIntersect(
        position.y, position.y+sprite.getSize().y,
        colCandidate->position.y, colCandidate->position.y+colCandidate->sprite.getSize().y
    );

    if(collision){ //placeholder
        velocity = -velocity;
        colCandidate->velocity = -colCandidate->velocity;
    }
}