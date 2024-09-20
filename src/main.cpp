#include <raylib.h>
#include <iostream>
#include "Grid.h"

int main()
{
    

    const int screenWidth = 300;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Course Tetris");
    SetTargetFPS(60); 

    Grid grid = Grid();
    //grid.grid[0][0] = 1;
    grid.Print();   

    while (!WindowShouldClose())
    {
        BeginDrawing();
        grid.Draw();
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}