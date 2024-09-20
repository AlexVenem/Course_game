#include <raylib.h>
#include <iostream>
#include "Grid.h"
#include "engine.h"
#include "colours.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    

    const int screenWidth = 510;
    const int screenHeight = 630;

    InitWindow(screenWidth, screenHeight, "Course Tetris");
    SetTargetFPS(60); 

    Font font = LoadFontEx("Font/SmallestPixel7.ttf", 64, 0, 0);

    Game game = Game();

    //Grid grid = Grid();
    //grid.grid[0][0] = 1;
    //grid.Print();   

    while (!WindowShouldClose())
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkGrey);
        DrawTextEx(font, "Score", {355, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightGrey);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightGrey);
        game.Draw();
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}