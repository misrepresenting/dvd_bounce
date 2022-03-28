#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "DVDBox.h"


void renderThread(sf::RenderWindow* window) {
    sf::Clock deltaClock;

    // rand generator init
    std::random_device rd;
    std::mt19937 gen(rd());


    DVDBox dvdBouncer(sf::Vector2f(50,50), sf::Vector2f(200,200));
    dvdBouncer.setColor(gen);

    while (window->isOpen()) {
        sf::Time dt = deltaClock.restart();

        dvdBouncer.step(dt.asSeconds());
        dvdBouncer.checkCollide(window, gen);

        window->clear();
        window->draw(dvdBouncer);
        window->display();
    }
}