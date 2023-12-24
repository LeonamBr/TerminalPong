#include "Ball.h"
#include <iostream>
#include <Windows.h>

Ball::Ball(int startX, int startY) : originalX(startX), originalY(startY), x(startX), y(startY),
                                     directionX(-1), directionY(-1) {}

void Ball::reset() {
    x = originalX;
    y = originalY;
    directionX = -1;
    directionY = -1;
}

int Ball::getX() const {
    return x;
}

int Ball::getY() const {
    return y;
}

void Ball::move() {
    x += directionX;
    y += directionY;
}

void Ball::changeDirection(int dx, int dy) {
    directionX = dx;
    directionY = dy;
}

int Ball::getYdirection() const
{
    return directionY;
}

int Ball::getXdirection() const
{
    return directionX;
}

void Ball::draw() const {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    std::cout << "o";
}
