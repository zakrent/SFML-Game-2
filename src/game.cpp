#include "game.h"

Game::Game(){
    window.create(VideoMode(600, 600), "Game");
    window.setFramerateLimit(30);
}

Game::~Game(){
    window.close();
}

void Game::mainLoop(){

    Object object1(50, 50, 20, 20, 0, 0);
    Object object2(150, 100, 20, 20, -2, -1);
    scene.addObject(&object1);
    scene.addObject(&object2);

    while(window.isOpen()) {

        //Event handling
        Event event;
        while(window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }

        }

        //Update and draw
        window.clear();
        scene.update();
        scene.draw(window);
        window.display();

    }
}
