#pragma once
#include <raylib.h>
#include <vector>

class Grid{
    public:
        Grid();
        void Initialize();
        void Draw();
        void Print();
        int grid[20][10];
    private:
        int pxperCell;
        int numRow;
        int numCol;
        std::vector<Color> colours;
};