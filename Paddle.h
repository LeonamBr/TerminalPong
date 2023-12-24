#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
private:
    int y;
    int originalY;
    int width;

public:
    Paddle(int startY, int paddleWidth);
    void reset();
    int getY() const;
    void moveUp();
    void moveDown();
    void draw() const;
};

#endif