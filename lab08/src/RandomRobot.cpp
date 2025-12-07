#include <RandomRobot.h>
#include <Maze.h>
#include <random>
void RandomRobot::nextMove(Maze& maze, int& newX, int& newY)
{
    int candidateX, candidateY;
    do {
        candidateX = this->getX() + dist(eng);
        candidateY = this->getY() + dist(eng);
    } while ((candidateX == this->getX() && candidateY == this->getY()) ||
             candidateX < 0 || candidateY < 0 || 
             candidateX >= maze.getWidth() || candidateY >= maze.getHeight()||
            maze.isWall(candidateX, candidateY));
    newX = candidateX;
    newY = candidateY;
}