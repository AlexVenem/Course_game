#include "block.h"

Block::Block()
{
    pxperCell = 30;
    rotationState = 0;
    rowOffset = 0;
    columnOffset = 0;
    colours = GetCellColours();
}

void Block::Draw(int offsetX, int offsetY)
{
    std::vector<Position> tiles = GetCellPositions();
    for (Position item : tiles)
    {
        DrawRectangle(item.column * pxperCell + offsetX, item.row * pxperCell + offsetY, pxperCell - 1, pxperCell - 1, colours[id]);
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for (Position item : tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate()
{
    rotationState++;
    if (rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}

void Block::UndoRotation()
{
    rotationState--;
    if (rotationState == -1)
    {
        rotationState = cells.size() - 1;
    }
}
