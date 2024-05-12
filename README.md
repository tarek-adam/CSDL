# CSDL

# Conway's Game of Life

Welcome to the Conway's Game of Life project!

## Introduction

Conway's Game of Life is a cellular automaton devised by mathematician John Horton Conway in 1970. This implementation is in C++ and runs in a text-based mode.

## Features

- **Start Game**: Begin the Game of Life simulation with an initial grid setup.
- **Random Population**: Generate a random initial population and start the game.
- **Load Population**: Load a population from a text file and start the game.
- **Save Population**: Save the current population to a text file.
- **Exit**: Quit the program.

## How to Run the Program

1. **Compile**: Use your preferred C++ compiler to compile the program.
    ```bash
    g++ -o game_of_life main.cpp game_of_life.cpp file_io.cpp
    ```

2. **Run**: Execute the program from your terminal or command prompt.
    ```bash
    ./game_of_life
    ```

3. **Interact**: Follow the on-screen instructions to interact with the game.

## Code Structure

- `main.cpp`: Contains the main function and the program's menu.
- `game_of_life.cpp` and `game_of_life.h`: Define the Game of Life logic and grid management.
- `file_io.cpp` and `file_io.h`: Handle file input and output for loading and saving populations.

## Additional Information

For more information about the Game of Life and its rules, please visit the [Wikipedia page](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).

## Contribution

Feel free to open issues, suggest improvements, or contribute to this project via pull requests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

