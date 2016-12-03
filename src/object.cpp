#include "object.h"
#include <math.h>

Object::Object(){};

Object::Object(float _x, float _y,float _xSize, float _ySize, bool _isSolid){
    isSolid = _isSolid;
    isStatic = true;
    position = {_x, _y};
    sprite.setSize(sf::Vector2f{_xSize, _ySize});
}

Object::Object(float _x, float _y,float _xSize, float _ySize, float _xSpeed, float _ySpeed, int _mass, bool _isSolid){
    isSolid = _isSolid;
    isStatic = false;
    mass = _mass;
    position = {_x, _y};
    velocity = {_xSpeed, _ySpeed};
    sprite.setSize(sf::Vector2f{_xSize, _ySize});
}

void Object::update(){
    if(!isStatic){
        position.x += velocity.x;
        position.y += velocity.y;
    }
    sprite.setPosition(position);
}

bool rangeIntersect(float min0,float max0,float min1,float max1){
    return max0 > min1 && min0 < max1;
}
void Object::checkCollision(Object* &colCandidate){
    if(isSolid && colCandidate->isSolid){
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
            if(!isStatic){
                velocity = - velocity;
                position += velocity;
            }
            if(!colCandidate->isStatic){
                colCandidate->velocity = -colCandidate->velocity;
                colCandidate->position += colCandidate->velocity;
            }
        }
    }
}
