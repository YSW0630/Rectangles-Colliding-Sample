#include "MyBox.h"
#include <iostream>

MyBox::MyBox(float xPos, float yPos, sf::Color color, float width, float height)
{
  box.setSize(sf::Vector2f(width, height));
  box.setPosition(sf::Vector2f(xPos, yPos));
  box.setFillColor(color);
}

void MyBox::handleInput()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    lastKey = sf::Keyboard::Up;
    movement.y -= moveSpeed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    lastKey = sf::Keyboard::Down;
    movement.y += moveSpeed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    lastKey = sf::Keyboard::Right;
    movement.x += moveSpeed;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    lastKey = sf::Keyboard::Left;
    movement.x -= moveSpeed;
  }
}

void MyBox::update(MyBox &other)
{
  movement = {0.f, 0.f};
  handleInput();
  applyMovement(other);
}

void MyBox::pushBox(MyBox &other)
{
  box.move(movement / damping);
  other.box.move(movement / damping);
}

void MyBox::applyMovement(MyBox &other)
{
  if (isColliding(other) == false) {
    keyLock = false;
    box.move(movement);
    return;
  }
  // Is collided
  if (keyLock == false)
  {
    collidedKey = lastKey;
    keyLock = true;
  }
  else if (collidedKey != lastKey &&
           (lastKey == sf::Keyboard::Left ||
            lastKey == sf::Keyboard::Right ||
            lastKey == sf::Keyboard::Up ||
            lastKey == sf::Keyboard::Down))
  {
    box.move(movement);
  }
  else if (collidedKey == lastKey &&
           (lastKey == sf::Keyboard::Left ||
            lastKey == sf::Keyboard::Right ||
            lastKey == sf::Keyboard::Up ||
            lastKey == sf::Keyboard::Down))
  {
    pushBox(other);
  }
}

void MyBox::draw(sf::RenderWindow &window)
{
  window.draw(box);
}

bool MyBox::isColliding(const MyBox &other) const
{
  return box.getGlobalBounds().intersects(other.box.getGlobalBounds());
}