#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "map.h"

using namespace sf;

class Game{
private:
    RenderWindow window;
    sf::Mouse mouse;
    Map scene;
public:
    Game();
    ~Game();
    void mainLoop();
};
