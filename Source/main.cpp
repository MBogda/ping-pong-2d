#include <SFML/Graphics.hpp>
#include "gameobjects.h"

const sf::Rect<float> Board(50, 100, 700, 450);
const float WallThickness = 10;
const float Speed = 3;  //3..5

enum RacketSide {Left, Right};

Racket initRacket(RacketSide side, float speed = Speed, const sf::Color & color = sf::Color::White,
                  const sf::Vector2f & size = sf::Vector2f(15, 125))
{
    Racket racket(speed);
    racket.setSize(size);
    racket.setOrigin(size.x / 2, size.y / 2);
    racket.setFillColor(color);
    racket.setOutlineThickness(-1);
    racket.setOutlineColor(sf::Color::Black);

    if (side == Left)
        racket.setPosition(Board.left + WallThickness + size.x / 2, Board.top + Board.height / 2);
    else
        racket.setPosition(Board.left + Board.width - WallThickness - size.x / 2, Board.top + Board.height / 2);

    return racket;
}

Ball initBall(float speed = Speed, const sf::Color & color = sf::Color::White, float radius = 12)
{
    Ball ball(speed);
    ball.setRadius(radius);
    ball.setOrigin(radius, radius);
    ball.setFillColor(color);
    ball.setOutlineThickness(-1);
    ball.setOutlineColor(sf::Color::Black);
    ball.setPosition(Board.left + Board.width / 2, Board.top + Board.height / 2);
    ball.setUpRight();
    return ball;
}

sf::RectangleShape initWall(const sf::Vector2f & size = sf::Vector2f(0, 0), const sf::Vector2f & position = sf::Vector2f(0, 0),
                            const sf::Color & color = sf::Color::White)
{
    sf::RectangleShape wall(size);
    wall.setFillColor(color);
    wall.setOutlineThickness(-1);
    wall.setOutlineColor(sf::Color::Black);
    wall.setPosition(position);
    return wall;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ping Pong 2D");
    window.setFramerateLimit(60);
    //window.setVerticalSyncEnabled(true);

    sf::RectangleShape wallUp = initWall(sf::Vector2f(Board.width, WallThickness), sf::Vector2f(Board.left, Board.top));
    sf::RectangleShape wallDown = initWall(sf::Vector2f(Board.width, WallThickness),
                                           sf::Vector2f(Board.left, Board.top + Board.height - WallThickness));
    sf::RectangleShape wallLeft = initWall(sf::Vector2f(WallThickness, Board.height - 2 * WallThickness),
                                           sf::Vector2f(Board.left, Board.top + WallThickness));
    sf::RectangleShape wallRight = initWall(sf::Vector2f(WallThickness, Board.height - 2 * WallThickness),
                                          sf::Vector2f(Board.left + Board.width - WallThickness, Board.top + WallThickness));
    Racket racketLeft = initRacket(Left);
    Racket racketRight = initRacket(Right);
    Ball ball = initBall();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyPressed:
                if (event.key.code != sf::Keyboard::Escape)
                    break;
            case sf::Event::Closed:
                //вызвать окно предупреждения о выходе
                window.close();
                break;
            default:
                break;
            }
        }

        //manipulate objects;
        if (wallUp.getGlobalBounds().intersects(racketLeft.getGlobalBounds()) == false)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
                    sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                racketLeft.goUp();
                racketRight.goUp();
            }
        }
        if (wallDown.getGlobalBounds().intersects(racketLeft.getGlobalBounds()) == false)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
                    sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                racketLeft.goDown();
                racketRight.goDown();
            }
        }

        if (wallUp.getGlobalBounds().intersects(ball.getGlobalBounds()) == true)
        {
            if (ball.isUpLeft())
                ball.setDownLeft();
            else if (ball.isUpRight())
                ball.setDownRight();
        }
        if (wallDown.getGlobalBounds().intersects(ball.getGlobalBounds()) == true)
        {
            if (ball.isDownLeft())
                ball.setUpLeft();
            else if (ball.isDownRight())
                ball.setUpRight();
        }
        if (racketLeft.getGlobalBounds().intersects(ball.getGlobalBounds()) == true)
        {
            if (ball.isUpLeft())
                ball.setUpRight();
            else if (ball.isDownLeft())
                ball.setDownRight();
        }
        if (racketRight.getGlobalBounds().intersects(ball.getGlobalBounds()) == true)
        {
            if (ball.isUpRight())
                ball.setUpLeft();
            else if (ball.isDownRight())
                ball.setDownLeft();
        }
        if ((wallLeft.getGlobalBounds().intersects(ball.getGlobalBounds()) == true) ||
            (wallRight.getGlobalBounds().intersects(ball.getGlobalBounds()) == true))
        {
            //game over
            window.close();
        }
        ball.moveObject();

        //draw objects
        window.clear(sf::Color(0, 127, 0));

        window.draw(wallUp);
        window.draw(wallDown);
        window.draw(wallLeft);
        window.draw(wallRight);
        window.draw(racketLeft);
        window.draw(racketRight);
        window.draw(ball);

        window.display();
    }
    return 0;
}
