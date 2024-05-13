#include "raylib.h" // Include the Raylib library header file for graphics
#include "Grid.hpp" // Include the Grid class header file

int main()
{
    // Define constants for screen dimensions, cell size, and frames per second
    const int screenWidth = 700;
    const int screenHeight = 700;
    const int cellSize = 20;
    const int fps = 3;

    // Initialize the window with specified dimensions and title
    InitWindow(screenWidth, screenHeight, "Game of Life");

    // Set the target frames per second for the application
    SetTargetFPS(fps);

    // Create an instance of the Grid class based on screen and cell dimensions
    Grid grid(screenWidth / cellSize, screenHeight / cellSize, cellSize);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Begin drawing on the window
        BeginDrawing();
        
        // Clear the background with white color
        ClearBackground(RAYWHITE);

        // Update the grid (advance the simulation by one step)
        grid.Update();

        // Draw the grid on the window
        grid.Draw();

        // End drawing on the window
        EndDrawing();
    }

    // Close the window
    CloseWindow();
}

    // Return 0 to indicate successful program execution
    return 0;