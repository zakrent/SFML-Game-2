#include <vector>
#include "object.h"

class Map{
public: //placeholder
    std::vector < Object* > objects;
    sf::Vector2f size;
public:
    Map();
    Map(sf::Vector2f _size);
    void addObject(Object *object);
    void draw(sf::RenderTarget &window);
    void update();
    std::vector<Object*> getObjects();
};
