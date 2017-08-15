#ifndef GAMEOBJECTS
#define GAMEOBJECTS

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "movablegameobject.h"

class Racket final : public sf::RectangleShape, public MovableGameObject
{
private:
    void moveObject() override final;
    using MovableGameObject::setDirection;
    using MovableGameObject::getDirection;
public:
    Racket(float speed = 0);
    void goUp();
    void goDown();
};

class Ball final : public sf::CircleShape, public MovableGameObject
{
private:
    using MovableGameObject::setDirection;
    using MovableGameObject::getDirection;
public:
    Ball(float speed = 0);
    void moveObject() override final;
    void setUpLeft();
    void setUpRight();
    void setDownLeft();
    void setDownRight();
    bool isUpLeft();
    bool isUpRight();
    bool isDownLeft();
    bool isDownRight();
};

#endif // GAMEOBJECTS
