#ifndef WAVEFRONT_ROBOT_H
#define WAVEFRONT_ROBOT_H
#include "Robot.h"
#include <random>
class WavefrontRobot : public Robot
{
    public:
        WavefrontRobot(Maze& maze);
        void nextMove(Maze&,int&,int&) override;

    private:
        std::vector<std::vector<int>> wavefrontMap;
};
#endif // RANDOM_ROBOT_H