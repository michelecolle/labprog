#ifndef MY_CLASS_H // include guard, per evitare inclusioni multiple
#define MY_CLASS_H
#include <string>
#include <vector>
#include <ostream>

class Maze
{
    public:
        Maze(const std::string& filename);
        Maze(const std::vector<std::string>& layout);
        ~Maze() = default;
        bool isWall(int x, int y) const;
        bool isExit(int x, int y) const;
        int getStartX() const;
        int getStartY() const;
        int getWidth() const;
        int getHeight() const;
        // const accessor for layout
        const std::vector<std::string>& getLayout() const { return layout; }

    private:
        std::vector<std::string> layout;
        int width;
        int height;
        int start_x, start_y;
        int exit_x, exit_y;
};

std::ostream& operator<<(std::ostream& os, const Maze& r);


#endif