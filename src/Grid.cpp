#include "Grid.h"
#include "colours.h"
#include <iostream>

Grid::Grid()
{
    numRow = 20;
    numCol = 10;
    pxperCell = 30;
    Initialize();
    colours = GetCellColours();
}

void Grid::Initialize()
{
    for(int row = 0; row < numRow; row++) {
        for(int colum = 0; colum < numCol; colum++)
            grid[row][colum] = 0;
    }
}

void Grid::Print()
{
    for(int row = 0; row < numRow; row++)
    {
        for(int colum = 0; colum < numCol; colum++)
            std::cout << grid[row][colum] << " ";
        std::cout << std::endl;
    }
}

void Grid::Draw()
{
    for (int row = 0; row < numRow; row++)
        for (int column = 0; column < numCol; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column * pxperCell, row * pxperCell, pxperCell - 1, pxperCell - 1, colours[cellValue]);
        }
}