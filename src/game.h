#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "map.h"

using namespace sf;

class Game{
private:
    RenderWindow window;
    Map scene;
public:
    Game();
    ~Game();
    void mainLoop();
};
