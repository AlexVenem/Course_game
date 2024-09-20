#pragma once
#include <raylib.h>
#include <vector>

class Grid{
    public:
        Grid();
        void Initialize();
        void Draw();
        void Print();
        bool IsCellOutside(int row, int column);
        bool IsCellEmpty(int row, int column);
        int ClearFullRows();
        int grid[20][10];
    private:
        int pxperCell;
        int numRow;
        int numCol;
        bool IsRowFull(int row);
        void ClearRow(int row);
        void MoveRowDown(int row, int numRows);
        std::vector<Color> colours;
};