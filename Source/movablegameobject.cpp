#include "movablegameobject.h"

MovableGameObject::MovableGameObject(float speed, const sf::Vector2i & direction)
    : Speed(speed), Direction(direction) {}

void MovableGameObject::setSpeed(float speed)
{
    Speed = speed;
}

float MovableGameObject::getSpeed() const
{
    return Speed;
}

void MovableGameObject::setDirection(sf::Vector2i & direction)
{
    Direction = direction;
}

sf::Vector2i MovableGameObject::getDirection() const
{
    return Direction;
}
