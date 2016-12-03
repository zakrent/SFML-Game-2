#include "game.h"
#define MAP_SIZE 20

Game::Game(){
    window.create(VideoMode(600, 600), "Game");
    window.setFramerateLimit(1024);
}

Game::~Game(){
    window.close();
}

void Game::mainLoop(){

    for(int i=0; i < MAP_SIZE; i++){
        for(int y=0; y < MAP_SIZE; y++){
            if(i == 0 || y == 0 || i == MAP_SIZE-1 || y == MAP_SIZE-1){
                scene.addObject(new Object(i*20, y*20, 18, 18, true));
                scene.objects[scene.objects.size()-1]->sprite.setFillColor(sf::Color::Blue);
            }else{
                scene.addObject(new Object(i*20, y*20, 18, 18, false));
            }
        }
    }

    Object object1(80, 80, 20, 20, 2, 20, 10, true);
    object1.sprite.setFillColor(sf::Color::Red);
    scene.addObject(&object1);

    Object object2(80, 50, 20, 20, 3, -10, 1, true);
    object2.sprite.setFillColor(sf::Color::Green);
    scene.addObject(&object2);

    Object object3(15, 50, 20, 20, -8, -20, 20, true);
    object3.sprite.setFillColor(sf::Color::Black);
    scene.addObject(&object3);

    Object dummy(5000, 5000, 0, 0, 0, 0, 0, false);//last object is bugged for now i'll add dummy one
    dummy.sprite.setFillColor(sf::Color::Transparent);
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
