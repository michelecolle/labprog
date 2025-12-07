// ...existing code...
#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <fstream>
#include "Maze.h"
#include "RandomRobot.h"
#include "WavefrontRobot.h"

int main()
{
    Maze maze("input.txt");

    std::cout << maze << std::endl;

    WavefrontRobot robot(maze);
    RandomRobot robot2(maze);

    
    std::cout << "Press Ctrl+C to close "<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    while (true) {
        int x = 0;
        int y = 0;
        robot.move(maze);
        x = robot.getX();
        y = robot.getY();
        // build a buffer from the maze layout so we can overlay path and robot
        const auto& layout = maze.getLayout();
        const int H = maze.getHeight();
        const int W = maze.getWidth();

        std::vector<std::string> buffer;
        buffer.reserve(H);
        for (int row = 0; row < H; ++row) buffer.push_back(layout[row]); // copy rows

        // mark the path with '.' using robot's recorded path
        const auto pathX = robot.getPathX();
        const auto pathY = robot.getPathY();
        const size_t pathLen = std::min(pathX.size(), pathY.size());
        for (size_t i = 0; i < pathLen; ++i) {
            int px = pathX[i];
            int py = pathY[i];
            if (px >= 0 && px < W && py >= 0 && py < H && !maze.isWall(px, py)) {
                // don't overwrite the exit or start markers if you prefer; here we mark path
                buffer[py][px] = '.';
            }
        }

        // place the robot current position last (so it overrides path)
        if (x >= 0 && x < W && y >= 0 && y < H) buffer[y][x] = 'X';

        // produce output string
        std::string output;
        for (int row = 0; row < H; ++row) {
            output += buffer[row];
            output += '\n';
        }
        std::cout << "\033[" << maze.getHeight() << "A" << output;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (maze.isExit(x, y)) {
            std::cout << "Robot has reached the exit!" << std::endl;
            break;
        }
    }

    return 0;
}
