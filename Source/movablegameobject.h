#ifndef MOVABLEGAMEOBJECT_H
#define MOVABLEGAMEOBJECT_H

#include <SFML/System.hpp>

class MovableGameObject
{
//private:
protected:
    float Speed;
    sf::Vector2i Direction;
public:
    MovableGameObject(float speed = 0, const sf::Vector2i & direction = sf::Vector2i(0, 0));
    void setSpeed(float speed);
    float getSpeed() const;
    void setDirection(sf::Vector2i & direction);
    sf::Vector2i getDirection() const;
    virtual void moveObject() = 0;
};

#endif // MOVABLEGAMEOBJECT_H
