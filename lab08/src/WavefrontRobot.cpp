#include "WavefrontRobot.h"
#include "Maze.h"
#include <vector>
#include <iostream>
#include <iomanip>

void BFS(std::vector<std::vector<int>>& graph, 
    std::vector<int>& fringeX, 
    std::vector<int>& fringeY)
{
    while(!fringeX.empty())
    {
        int currentX = fringeX.back();
        int currentY = fringeY.back();
        fringeX.pop_back();
        fringeY.pop_back();
        std::vector<int> neighborsX = {-1,0,1, -1,0,1,  -1,0,1};
        std::vector<int> neighborsY = {1,1,1, 0,0,0, -1,-1,-1};
        int currentValue = graph[currentY][currentX];
        for (size_t i = 0; i < neighborsX.size(); i++)
        {
            int nx = currentX + neighborsX[i];
            int ny = currentY + neighborsY[i];
            //controlli di validita
            if(nx<0 || ny<0 || nx>=graph[0].size() 
            || ny>=graph.size()
            || (nx==currentX && ny==currentY))
                continue;  

            int neighborValue = graph[ny][nx];

            //in questo caso il nondo non é stato ancora visitato e non é un muro
            if(neighborValue==0)
            {
                fringeX.push_back(nx);
                fringeY.push_back(ny);
                graph[ny][nx] = currentValue +1;
            }       
        }
        //BFS(graph, fringeX, fringeY,parentValue +1);
    }
}
WavefrontRobot::WavefrontRobot(Maze& maze): Robot(maze)
{
    wavefrontMap = std::vector<std::vector<int>>(maze.getHeight(), std::vector<int>(maze.getWidth(), 0));
    int exitX = -1;
    int exitY = -1;
    int startX = maze.getStartX();
    int startY = maze.getStartY();
    for (size_t y = 0; y < maze.getHeight(); y++)
    {
        for (size_t x = 0; x < maze.getHeight(); x++)
        {
            wavefrontMap[y][x] = 0; // inizializzo tutto a 0
            if(maze.isExit(x,y)){
                exitX = x; exitY = y;
                wavefrontMap[y][x] = 2;

            }
            if(maze.isWall(x,y)){
                wavefrontMap[y][x] = -1; // for walls
            }

        }   
    }
    //a qusto punto ho la radice dell albero e ho i muri a -1, ora devo completare il wavefront
    std::vector<int> fringeX{exitX};
    std::vector<int> fringeY{exitY};
    std::cout<<"Root at: ("<<exitX<<","<<exitY<<")\n";
    BFS(wavefrontMap, fringeX, fringeY);
    std::cout<<"Wavefront Map: \n";
    const int fieldWidth = 3;

    for (size_t y = 0; y < maze.getHeight(); ++y)
    {
        for (size_t x = 0; x < maze.getWidth(); ++x)
        {
            int v = wavefrontMap[y][x];
            if (v < 0) {
                // wall: print a symbol instead of a negative number
                std::cout << std::setw(fieldWidth) << '#';
            } else {
                // numeric distance, right-aligned
                std::cout << std::setw(fieldWidth) << v;
            }
        }
        std::cout << '\n';
    }
    
}


void WavefrontRobot::nextMove(Maze& maze, int& newX, int& newY)
{
    int currentX = this->getX();
    int currentY = this->getY();
    std::vector<int> neighborsX = {-1,0,1, -1,0,1,  -1,0,1};
    std::vector<int> neighborsY = {1,1,1, 0,0,0, -1,-1,-1};
    int minValue = wavefrontMap[currentY][currentX];
    int bestX = currentX;
    int bestY = currentY;
    for (size_t i = 0; i < neighborsX.size(); i++)
    {
        int nx = currentX + neighborsX[i];
        int ny = currentY + neighborsY[i];
        //controlli di validita
        if(nx<0 || ny<0 || nx>=maze.getWidth() 
        || ny>=maze.getHeight()
        || (nx==currentX && ny==currentY)
        || maze.isWall(nx,ny))
            continue;  

        int neighborValue = wavefrontMap[ny][nx];

        if(neighborValue>0 && neighborValue < minValue)
        {
            minValue = neighborValue;
            bestX = nx;
            bestY = ny;
        }       
    }
    newX = bestX;
    newY = bestY;
}