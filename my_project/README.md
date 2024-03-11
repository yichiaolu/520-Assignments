# 2048 Game

## Overview
This project is a C++ implementation of the classic 2048 game. 

The goal is to slide numbered tiles on a grid to combine them and create a tile with the number 2048.


## Key Challenges
- Implementing the game logic to handle tile movement and combination efficiently.
- Managing user input and updating the game state accordingly.
- Implementing a timer to limit the duration of the game.

## Installation And Run
1. Make sure you have a C++ compiler installed on your system.
2. Clone this repository to your local machine：
    
    "git clone https://github.com/yichiaolu/520-Assignments.git"
3. Navigate to the project directory:
   
    "cd 520-Assignments/my_project"
4. Compile the code using the following command: 

    "g++ -o main main.cc -std=c++11"
5. Build Docker container:

    "docker build -t my_project."
6. Run Docker container:

    "docker run -p 8888:8765 -v $PWD:/source -it klavins/enviro:v1.1 bash"
7. Run the project in the Docker container:

    "./main"

## Game Images

Game Start

![Times Up](https://github.com/yichiaolu/520-Assignments/raw/main/my_project/start.png)
Game Play

![Times Up](https://github.com/yichiaolu/520-Assignments/raw/main/my_project/running.png)
Lose.

![Times Up](https://github.com/yichiaolu/520-Assignments/raw/main/my_project/lose.png)
Time's up.

![Times Up](https://github.com/yichiaolu/520-Assignments/raw/main/my_project/times.up.png)


## Usage
1. Run the compiled executable using the following command:
./main\
2. Use the following keys to control tile movement:
- w: Move tiles upwards.
- s: Move tiles downwards.
- a: Move tiles to the left.
- d: Move tiles to the right.
3. Try to combine tiles to reach the 2048 tile before the timer runs out!

## Acknowledgements
- This project was inspired by the original 2048 game created by Gabriele Cirulli.
- Parts of the code and ideas in this project were adapted from [JackHCC's GitHub repository](https://github.com/JackHCC).


}
