#include "game.h"
#define MAP_SIZE 20

Game::Game(){
    window.create(VideoMode(600, 600), "Game");
    window.setFramerateLimit(60);
}

Game::~Game(){
    window.close();
}

void Game::mainLoop(){

    for(int i=0; i < MAP_SIZE; i++){
        for(int y=0; y < MAP_SIZE; y++){
            if(i == 0 || y == 0 || i == MAP_SIZE-1 || y == MAP_SIZE-1){
                scene.addObject(new Object(i*20, y*20, 18, 18, 0, 0, true));
            }else{
                scene.addObject(new Object(i*20, y*20, 18, 18, 0, 0, false));
            }
        }
    }

    Object object1(80, 80, 20, 20, 5, -3, true);
    object1.sprite.setFillColor(sf::Color::Yellow);
    scene.addObject(&object1);

    Object object2(80, 100, 20, 20, -2, -5, true);
    object2.sprite.setFillColor(sf::Color::Yellow);
    scene.addObject(&object2);

    Object object3(110, 100, 20, 20, -6, -5, true);
    object2.sprite.setFillColor(sf::Color::Yellow);
    scene.addObject(&object3);

    Object dummy(10000, 10000, 0, 0, 0, 0, false);//last object is bugged for now i'll add dummy one
    object2.sprite.setFillColor(sf::Color::Transparent);
    scene.addObject(&dummy);

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
