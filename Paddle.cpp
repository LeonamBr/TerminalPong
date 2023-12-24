#include "Paddle.h"
#include <iostream>
#include <Windows.h>

Paddle::Paddle(int startY, int paddleWidth) : originalY(startY), y(startY), width(paddleWidth) {}

void Paddle::reset() {
    y = originalY;
}

int Paddle::getY() const {
    return y;
}

void Paddle::moveUp() {
    if (y > 1)
        y--;
}

void Paddle::moveDown() {
    if (y < 20)
        y++;
}

void Paddle::draw() const {
    COORD pos;
    for (int i = -1; i <= 1; ++i) {
        pos.X = (width == 5) ? 2 : width - 1;
        pos.Y = y + i;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        std::cout << "|\n";
    }
}
