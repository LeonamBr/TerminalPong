#ifndef BALL_H
#define BALL_H

class Ball {
private:
    int x, y;
    int originalX, originalY;
    int directionX, directionY;

public:
    Ball(int startX, int startY);
    void reset();
    int getX() const;
    int getY() const;
    void move();
    void changeDirection(int dx, int dy);
    int getYdirection() const;
    int getXdirection() const;
    void draw() const;
};

#endif