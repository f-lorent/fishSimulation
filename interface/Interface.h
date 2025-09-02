//
// Created by florent on 30/08/2025.
//

#ifndef FISHSIMULATION_INTERFACE_H
#define FISHSIMULATION_INTERFACE_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../World/World.h"

#define HEIGHT 1080
#define WIDTH 1920
#define RED 10
#define GREEN 43
#define BLUE 88
#define FISH_COUNT 200
#define TIME_COEFFICIENT 10


class Interface {
private:
    sf::RenderWindow window;
    sf::RectangleShape background;
    sf::Color backgroundColor;
    World world;

public:
    Interface(): window(sf::VideoMode(WIDTH, HEIGHT),"fishSimulation"),
    background(sf::Vector2f(WIDTH, HEIGHT)),
    backgroundColor(RED, GREEN, BLUE),
    world(FISH_COUNT)
    {
        background.setFillColor(backgroundColor);
    };
    void run();

private:
    void eventListener();

    void interfaceUpdate(double deltaTime);
    void interfaceRender();
};


#endif //FISHSIMULATION_INTERFACE_H