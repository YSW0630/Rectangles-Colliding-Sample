#include <SFML/Graphics.hpp>
#include "MyBox/MyBox.h"

int main() {
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  sf::RenderWindow window(sf::VideoMode(800, 600), "Hello World Game", sf::Style::Default, settings);
  //window.setVerticalSyncEnabled(true);

  // Initialize the size and position of boxes
  MyBox boxA(150, 250, sf::Color::Green);
  MyBox boxB(550, 250, sf::Color::Red);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    boxA.update(boxB);

    window.clear(sf::Color::Black);
    boxA.draw(window);
    boxB.draw(window);
    window.display();
  }

  return 0;
}
