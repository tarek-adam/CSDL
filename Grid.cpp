#include "Grid.hpp" // Include the Grid class header file

// Constructor definition for the Grid class
Grid::Grid(int width, int height, int cellSize) : width(width), height(height), cellSize(cellSize) {
    // Dynamically allocate memory for the 'cells' and 'nextGen' arrays
    cells = new int[width * height];
    nextGen = new int[width * height];
    
    // Initialize the cells with random values
    RandomizeCells();
}

// Destructor definition for the Grid class
Grid::~Grid() {
    // Deallocate the memory allocated for the 'cells' and 'nextGen' arrays
    delete[] cells;
    delete[] nextGen;
}

// Function to randomly initialize the cells
void Grid::RandomizeCells() {
    for (int i = 0; i < width * height; ++i) {
        cells[i] = GetRandomValue(0, 1);
    }
}

// Function to get the value of a cell at a specific position
int Grid::GetCell(int x, int y) {
    return cells[y * width + x];
}

// Function to set the value of a cell at a specific position
void Grid::SetCell(int x, int y, int value) {
    cells[y * width + x] = value;
}

// Function to count the number of live neighbors of a cell
int Grid::CountNeighbors(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int nx = (x + i + width) % width;
            int ny = (y + j + height) % height;
            count += GetCell(nx, ny);
        }
    }
    count -= GetCell(x, y);
    return count;
}

// Function to update the grid based on the rules of the Game of Life
void Grid::Update() {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            int neighbors = CountNeighbors(x, y);
            if (cells[y * width + x] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    nextGen[y * width + x] = 0; // Cell dies
                } else {
                    nextGen[y * width + x] = 1; // Cell survives
                }
            } else {
                if (neighbors == 3) {
                    nextGen[y * width + x] = 1; // Cell becomes alive
                } else {
                    nextGen[y * width + x] = 0; // Cell remains dead
                }
            }
        }
    }

    // Swap current and nextGen arrays
    int *temp = cells;
    cells = nextGen;
    nextGen = temp;
}

// Function to draw the grid on the screen
void Grid::Draw() {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (cells[y * width + x] == 1) {
                DrawRectangle(x * cellSize, y * cellSize, cellSize, cellSize, GREEN); // Draw live cell
            } else {
                DrawRectangle(x * cellSize, y * cellSize, cellSize, cellSize, RED); // Draw dead cell
            }
            DrawRectangleLines(x * cellSize, y * cellSize, cellSize, cellSize, WHITE); // Draw cell borders
        }
    }
}
