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
  inline bool isColliding(const MyBox&) const;

private:
  sf::RectangleShape box;
  sf::Vector2f movement;
  sf::Keyboard::Key lastKey;
  sf::Keyboard::Key collidedKey;
  float moveSpeed;
  float damping;
  bool keyLock;
};
