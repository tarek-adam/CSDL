
#ifndef GRID_H // Header guard to prevent multiple inclusions of the same header file
#define GRID_H

// Include necessary header files
#include "raylib.h"

// Declaration of the Grid class
class Grid
{
public:
    // Constructor declaration
    Grid(int width, int height, int cellSize);

    // Destructor declaration
    ~Grid();

    // Public member functions
    void Update(); // Function to update the grid state
    void Draw();   // Function to draw the grid

private:
    // Private member variables
    int width;    // Width of the grid
    int height;   // Height of the grid
    int cellSize; // Size of each cell
    int *cells;   // Pointer to an array representing the current state of the grid
    int *nextGen; // Pointer to an array representing the next generation of the grid

    // Private member functions
    void RandomizeCells();                 // Function to randomly initialize the cells
    int GetCell(int x, int y);             // Function to get the value of a cell at a specific position
    void SetCell(int x, int y, int value); // Function to set the value of a cell at a specific position
    int CountNeighbors(int x, int y);      // Function to count the number of live neighbors of a cell
};

#endif // GRID_H