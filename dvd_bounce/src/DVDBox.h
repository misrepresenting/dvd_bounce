#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

class DVDBox : public sf::RectangleShape {
    float xSize = 50;
    float ySize = 50;

public:
    float xVelocity = 125;
    float yVelocity = 125;
    sf::Color color;

    DVDBox(sf::Vector2f size, sf::Vector2f pos) : sf::RectangleShape(size) {
        setPosition(pos);
    };

    void step(float dt) {
        move(xVelocity * dt, yVelocity * dt);
    }

    void setColor(std::mt19937& gen) {
        std::uniform_int_distribution<int> randRGB(0, 255);
        setFillColor(sf::Color(randRGB(gen), randRGB(gen), randRGB(gen)));
    }

    void checkCollide(sf::Window* window, std::mt19937& gen) {
        sf::Vector2f pos = getPosition();
        sf::Vector2f size = static_cast<sf::Vector2f>(window->getSize());

        if (pos.x > size.x - xSize || pos.x < 0) {
            xVelocity *= -1;
            setColor(gen);
        }

        if (pos.y > size.y - ySize || pos.y < 0) {
            yVelocity *= -1;
            setColor(gen);
        }
    }
};