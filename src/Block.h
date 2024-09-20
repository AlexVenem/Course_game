#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colours.h"

class Block
{
public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int rows, int columns);
    void Rotate();
    void UndoRotation();
    int id;
    std::vector<Position> GetCellPositions();
    std::map<int, std::vector<Position>> cells;

private:
    int pxperCell;
    int rotationState;
    int rowOffset;
    int columnOffset;
    std::vector<Color> colours;
};