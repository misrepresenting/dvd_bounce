#include <SFML/Graphics.hpp>
#include <iostream>

void renderThread(sf::RenderWindow* window);

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 300), "dvd thing", sf::Style::Close);
    sf::Thread thread(&renderThread, &window);

    window.setActive(false);
    thread.launch();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

    }

    return 0;
}