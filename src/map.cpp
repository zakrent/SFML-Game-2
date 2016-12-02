#include "map.h"

Map::Map(){}

Map::Map(sf::Vector2f _size){
    size = _size;
}

void Map::addObject(Object *object){
    objects.push_back(object);
}

std::vector<Object*> Map::getObjects(){
    return objects;
}

void Map::draw(sf::RenderTarget &window){
    for(int i = 0; i < objects.size(); i++){
        window.draw(objects[i]->sprite);
    };
}

void Map::update(){
    for(int i = 0; i < objects.size(); i++){
        objects[i]->update();
        for(int x = i+1; x < objects.size(); x++){
            objects[i]->checkCollision(objects[x]);
        };
    };

}
