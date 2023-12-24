#ifndef GAME_H
#define GAME_H

#include "Paddle.h"
#include "Ball.h"
#include <thread>
#include <atomic>

class Game {
private:
    const short width;
    const short height;
    Paddle playerPaddle;
    Paddle aiPaddle;
    Ball ball;
    std::atomic<bool> quit;
    std::thread inputThread;
    std::thread updateThread;
    int playerScore;
    int aiScore;

public:
    Game(short w, short h);
    void draw() const;
    void update();
    void input();
    void run();
};

#endif