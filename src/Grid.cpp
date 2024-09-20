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
        for (int colum = 0; colum < numCol; colum++)
        {
            int cellValue = grid[row][colum];
            DrawRectangle(colum * pxperCell+11, row * pxperCell+11, pxperCell - 1, pxperCell - 1, colours[cellValue]);
        }
}

bool Grid::IsCellOutside(int row, int colum)
{
    if (row >= 0 && row < numRow && colum >= 0 && colum < numCol)
        return false;
    return true;
}

bool Grid::IsCellEmpty(int row, int colum)
{
    if (grid[row][colum] == 0)
        return true;
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for (int row = numRow - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0)
            MoveRowDown(row, completed);
    }
    return completed;
}

bool Grid::IsRowFull(int row)
{
    for (int colum = 0; colum < numCol; colum++)
    {
        if (grid[row][colum] == 0)
            return false;
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for (int colum = 0; colum < numCol; colum++)
        grid[row][colum] = 0;
}

void Grid::MoveRowDown(int row, int numRows)
{
    for (int colum = 0; colum < numCol; colum++)
    {
        grid[row + numRows][colum] = grid[row][colum];
        grid[row][colum] = 0;
    }
}