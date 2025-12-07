#include  <Maze.h>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>

// helper function to load and return layout from file
static std::vector<std::string> loadLayoutFromFile(const std::string& filename)
{
    try {
        std::fstream file(filename, std::ios::in);
        std::vector<std::string> data;
        std::string line;
        while (std::getline(file, line)) {
            data.push_back(line);
        }
        return data;
    }
    catch (const std::exception& e) {
        throw std::invalid_argument(e.what());
    }
}

Maze::Maze(const std::vector<std::string>& layout)
{
    this->layout = layout;
    height = layout.size();
    if (height == 0) {
        throw std::invalid_argument("Layout cannot be empty");
    }
    width = layout[0].size();
    for (const auto& row : layout) {
        if (row.size() != width) {
            throw std::invalid_argument("All rows must have the same width");
        }
    }

    bool start_found = false;
    bool exit_found = false;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (layout[y][x] == 'S') {
                start_x = x;
                start_y = y;
                start_found = true;
            } else if (layout[y][x] == 'E') {
                exit_x = x;
                exit_y = y;
                exit_found = true;
            }
        }
    }

    if (!start_found) {
        throw std::invalid_argument("Start position 'S' not found in layout");
    }
    if (!exit_found) {
        throw std::invalid_argument("Exit position 'E' not found in layout");
    }
}
Maze::Maze(const std::string& filename)
    : Maze(loadLayoutFromFile(filename))  // delegate to other constructor
{
}




bool Maze::isWall(int x, int y) const
{
    return layout[y][x] == '*';
}
bool Maze::isExit(int x, int y) const
{
    return (x == exit_x && y == exit_y);
}
int Maze::getStartX() const{return start_x;}
int Maze::getStartY() const{return start_y;}
int Maze::getWidth() const{return width;}
int Maze::getHeight() const{return height;}

std::ostream& operator<<(std::ostream& os, const Maze& r)
{
    for (const std::string& row : r.getLayout()) {
        os << row << '\n';
    }
    return os;
}