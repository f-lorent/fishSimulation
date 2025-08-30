//
// Created by florent on 30/08/2025.
//

#include "Interface.h"
#include <SFML/Graphics.hpp>

void Interface::eventListener() {
    sf::Event event;
    while (window.pollEvent(event))
        if (event.type == sf::Event::Closed)
            window.close();
}

void Interface::interfaceRender() {
    window.clear(backgroundColor);
    window.draw(background);
    window.display();
}

void Interface::run() {
    while (window.isOpen())
    {
        eventListener();
        interfaceRender();
    }
}


