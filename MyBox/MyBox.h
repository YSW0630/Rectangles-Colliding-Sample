#ifndef MYBOX_H
#define MYBOX_H

#pragma once
#include <SFML/Graphics.hpp>

class MyBox
{
public:
  MyBox(float, float, sf::Color, float width = 50, float height = 50);
  MyBox() = default;
  ~MyBox() = default;
  void handleInput();
  void update(MyBox&);
  void pushBox(MyBox&);
  void applyMovement(MyBox&);
  void draw(sf::RenderWindow&);
  bool isColliding(const MyBox&) const;

private:
  sf::RectangleShape box;
  sf::Vector2f movement {0.f, 0.f};
  sf::Keyboard::Key lastKey = sf::Keyboard::Unknown;
  sf::Keyboard::Key collidedKey = sf::Keyboard::Unknown;
  float moveSpeed = 0.5f;
  float damping = 2.f;
  bool keyLock = false;
};

#endif