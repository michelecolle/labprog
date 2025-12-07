#ifndef RANDOM_ROBOT_H
#define RANDOM_ROBOT_H
#include "Robot.h"
#include <random>
class RandomRobot : public Robot
{
    public:
        using Robot::Robot; // allow RandomRobot( Maze& ) via Robot(Maze&)
        void nextMove(Maze&,int&,int&) override;

    private:
        std::mt19937_64 eng{std::random_device{}()};
        std::uniform_int_distribution<int> dist{-1, 1};
};
#endif // RANDOM_ROBOT_H