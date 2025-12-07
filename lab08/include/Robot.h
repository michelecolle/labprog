#ifndef ROBOT_H // include guard, per evitare inclusioni multiple
#define ROBOT_H
#include "Maze.h"
#include <vector>

class Robot
{
    public:
        Robot(int startX, int startY) : x(startX), y(startY) 
        {
            pathX.push_back(x); pathY.push_back(y);
        };
        Robot(Maze& maze) : Robot(maze.getStartX(), maze.getStartY()) {};
        ~Robot() = default;
        void move(Maze& maze) {
            int nx = x, ny = y;
            // derived class decides the candidate new position
            nextMove(maze, nx, ny);
            x = nx; y = ny;
            pathX.push_back(x);
            pathY.push_back(y);
            
        }
        int getX() const { return x; };
        int getY() const { return y; };
        std::vector<int> getPathX() const { return pathX; };
        std::vector<int> getPathY() const { return pathY; };
    protected:
        virtual void nextMove(Maze& maze, int& newX, int& newY) = 0;
    private:
        int x;
        int y;
        std::vector<int> pathX;
        std::vector<int> pathY;    
};

#endif