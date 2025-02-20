#include "MyBox.h"

#include <iostream>

MyBox::MyBox(float xPos, float yPos, sf::Color color, float width, float height)
    : movement({0.f, 0.f}),
      lastKey(sf::Keyboard::Unknown),
      collidedKey(sf::Keyboard::Unknown),
      moveSpeed(0.1f),
      damping(2.0f),
      keyLock(false) {
  box.setSize(sf::Vector2f(width, height));
  box.setPosition(sf::Vector2f(xPos, yPos));
  box.setFillColor(color);
}

void MyBox::handleInput() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    lastKey = sf::Keyboard::Up;
    movement.y -= moveSpeed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    lastKey = sf::Keyboard::Down;
    movement.y += moveSpeed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    lastKey = sf::Keyboard::Right;
    movement.x += moveSpeed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    lastKey = sf::Keyboard::Left;
    movement.x -= moveSpeed;
  }
}

void MyBox::update(MyBox &other) {
  movement = {0.f, 0.f};
  handleInput();
  applyMovement(other);
}

void MyBox::pushBox(MyBox &other) {
  box.move(movement / damping);
  other.box.move(movement / damping);
}

void MyBox::applyMovement(MyBox &other) {
  if (isColliding(other) == false) {
    keyLock = false;
    box.move(movement);
    return;
  }
  // Is collided
  if (keyLock == false) {
    collidedKey = lastKey;
    keyLock = true;
  } else if (collidedKey != lastKey) {
    box.move(movement);
  } else if (collidedKey == lastKey) {
    pushBox(other);
  }
}

void MyBox::draw(sf::RenderWindow &window) { window.draw(box); }

inline bool MyBox::isColliding(const MyBox &other) const {
  return box.getGlobalBounds().intersects(other.box.getGlobalBounds());
}
