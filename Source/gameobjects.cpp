#include "gameobjects.h"

Racket::Racket(float speed)
{
    Speed = speed;
}

void Racket::moveObject()
{
    move(Speed * Direction.x, Speed * Direction.y);
}

void Racket::goUp()
{
    Direction = sf::Vector2i(0, -1);
    moveObject();
}

void Racket::goDown()
{
    Direction = sf::Vector2i(0, 1);
    moveObject();
}

Ball::Ball(float speed)
{
    Speed = speed;
}

void Ball::moveObject()
{
    move(Speed * Direction.x, Speed * Direction.y);
}

void Ball::setUpLeft()
{
    Direction = sf::Vector2i(-1, -1);
}

bool Ball::isUpLeft()
{
    return Direction == sf::Vector2i(-1, -1);
}

void Ball::setUpRight()
{
    Direction = sf::Vector2i(1, -1);
}

bool Ball::isUpRight()
{
    return Direction == sf::Vector2i(1, -1);
}

void Ball::setDownLeft()
{
    Direction = sf::Vector2i(-1, 1);
}

bool Ball::isDownLeft()
{
    Direction == sf::Vector2i(-1, 1);
}

void Ball::setDownRight()
{
    Direction = sf::Vector2i(1, 1);
}

bool Ball::isDownRight()
{
    Direction == sf::Vector2i(1, 1);
}
