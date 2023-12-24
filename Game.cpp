#include "Game.h"
#include <iostream>
#include <chrono>
#include <Windows.h>
#include <conio.h>

Game::Game(short w, short h) : width(w), height(h), playerPaddle(h / 2, 3), aiPaddle(h / 2, w - 3),
                               ball(w / 2, h / 2), quit(false), playerScore(0), aiScore(0) {}

void Game::draw() const {
    system("cls");
    playerPaddle.draw();
    aiPaddle.draw();
    ball.draw();

    // Desenhar o campo
    for (int i = 0; i < height; ++i) {
        COORD pos;
        pos.X = width / 2;
        pos.Y = i;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        std::cout << "|\n";
    }

    // Desenhar a pontuação
    COORD scorePos;
    scorePos.X = width / 2 - 10;
    scorePos.Y = 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), scorePos);
    std::cout << "Player: " << playerScore << " AI: " << aiScore;
}

void Game::update() {
    while (!quit) {
        ball.move();

        // Lógica para verificar se houve um ponto marcado
        if (ball.getX() == 0) {
            aiScore++;
            ball.reset();
        } else if (ball.getX() == width - 1) {
            playerScore++;
            ball.reset();
        }

        // Limitando o movimento da bola na parte superior e inferior
        if (ball.getY() == 0 || ball.getY() == height - 1)
            ball.changeDirection(ball.getXdirection(), -ball.getYdirection());
        
        // Verificar colisão com os paddles
        if (ball.getX() == 3) {
            if (ball.getY() >= playerPaddle.getY() && ball.getY() < playerPaddle.getY() + 3)
                ball.changeDirection(-ball.getXdirection(), ball.getYdirection());
        } else if (ball.getX() == width - 4) {
            if (ball.getY() >= aiPaddle.getY() && ball.getY() < aiPaddle.getY() + 3)
                ball.changeDirection(-ball.getXdirection(), ball.getYdirection());
        }

        // Lógica da IA para acompanhar a bola
        if (ball.getY() < aiPaddle.getY())
            aiPaddle.moveUp();
        else if (ball.getY() > aiPaddle.getY())
            aiPaddle.moveDown();

        draw();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Game::input() {
    while (!quit) {
        if (_kbhit()) {
            char key = _getch();
            switch (key) {
                case 'w':
                    playerPaddle.moveUp();
                    break;
                case 's':
                    playerPaddle.moveDown();
                    break;
                case 'q':
                    quit = true;
                    break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Game::run() {
    inputThread = std::thread(&Game::input, this);
    updateThread = std::thread(&Game::update, this);

    inputThread.join();
    updateThread.join();
}
