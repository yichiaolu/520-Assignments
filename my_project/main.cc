#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <unistd.h>

using namespace std;
auto start = std::chrono::system_clock::now();  //start time

int const ROW = 4;
int const COL = 4;
int game[ROW][COL] = {0};
  
//Control up, down, left and right
int const UP = 1;
int const DOWN = 2;
int const LEFT = 3;
int const RIGHT = 4;
  
//Game Status
int const GAME_OVER = 1;
int const GAME_WIN = 2;
int const GAME_CONTINUE = 3;
  
enum GameNum
{
    Game_2 = 2,
    Game_4 = 4,
    Game_8 = 8,
    Game_16 = 16,
    Game_32 = 32,
    Game_64 = 64,
    Game_128 = 128,
    Game_256 = 256,
    Game_512 = 512,
    Game_1024 = 1024,
    Game_2048 = 2048,
};
  
//Print the resulting array
void Print(std::chrono::duration<double> elapsed_seconds)
{
    cout << string(100, '\n');
    cout << " ** Slide to Peak, 2048 Awaits Your Conquest! ** " << endl;
    cout << "*Tip: Keep the largest number in a fixed corner!*" << endl << endl;

    int remaining_time = 120 - static_cast<int>(elapsed_seconds.count());
    cout << "Time left: " << remaining_time / 60 << " min " << remaining_time % 60 << " sec " << endl;

    for (int i = 0; i < ROW; ++i) {
        cout << "---------------------------------"<< endl;
        for (int j = 0; j < COL; ++j) {
            if (game[i][j] == 0) {
                cout <<"|   \t";
            } else {
                cout <<"|   " << game[i][j] << "\t";
            }
        }
        cout << "|" << endl;
    }
    cout << "---------------------------------"<< endl;
}

//Interface settings
bool CreateNumber()
{
    int x = -1;
    int y = -1;
    int times = 0;
    int maxTimes = ROW * COL;
    int whitch = rand() % 3;
    do
    {
        x = rand() % ROW;
        y = rand() % COL;
        ++times;
    } while (game[x][y] != 0 && times <= maxTimes);
  
    // Indicates that the grid is full
    if(times >= maxTimes)
    {
        return false;
    }
    else
    {
        GameNum num;
        if(whitch == 0)
        {
            num = Game_4;
        }
        else if(whitch)
        {
            num = Game_2;
        }
        game[x][y] = num;
    }
  
    return true;
}
  
void Process(int direction)
{
    switch (direction)
    {
    case UP:
        //The top line does not move
        for(int row = 1; row < ROW; ++row)
        {
            for(int crow = row; crow >= 1; --crow)
            {
                for(int col = 0; col < COL; ++col)
                {
                    //Previous grid is empty
                    if(game[crow-1][col] == 0)
                    {
                        game[crow-1][col] = game[crow][col];
                        game[crow][col] = 0;
                    }
                    else
                    {
                        //incorporation
                        if(game[crow-1][col] == game[crow][col])
                        {
                            game[crow - 1][col] *= 2;
                            game[crow][col] = 0;
                        }
  
                    }
                }
            }
        }
        break;
    case DOWN:
        //Bottom line does not move
        for(int row = ROW - 2; row >= 0; --row)
        {
            for(int crow = row; crow < ROW - 1; ++crow)
            {
                for(int col = 0; col < COL; ++col)
                {
                    //Previous grid is empty
                    if(game[crow + 1][col] == 0)
                    {
                        game[crow + 1][col] = game[crow][col];
                        game[crow][col] = 0;
                    }
                    else
                    {
                        //incorporation
                        if(game[crow + 1][col] == game[crow][col])
                        {
                            game[crow + 1][col] *= 2;
                            game[crow][col] = 0;
                        }
  
                    }
                }
            }
        }
        break;
    case LEFT:
        //Leftmost column does not move
        for(int  col = 1; col < COL; ++col)
        {
            for(int ccol = col; ccol >= 1; --ccol)
            {
                for(int row = 0; row < ROW; ++row)
                {
                    //Previous grid is empty
                    if(game[row][ccol-1] == 0)
                    {
                        game[row][ccol - 1] = game[row][ccol];
                        game[row][ccol] = 0;
                    }
                    else
                    {
                        //incorporation
                        if(game[row][ccol - 1] == game[row][ccol])
                        {
                            game[row][ccol - 1] *= 2;
                            game[row][ccol] = 0;
                        }
  
                    }
                }
            }
        }
        break;
    case RIGHT:
        // The rightmost column does not move
        for(int  col = COL - 2; col >= 0; --col)
        {
            for(int ccol = col; ccol <= COL - 2; ++ccol)
            {
                for(int row = 0; row < ROW; ++row)
                {
                    //Previous grid is empty
                    if(game[row][ccol + 1] == 0)
                    {
                        game[row][ccol + 1] = game[row][ccol];
                        game[row][ccol] = 0;
                    }
                    else
                    {
                        //incorporation
                        if(game[row][ccol + 1] == game[row][ccol])
                        {
                            game[row][ccol + 1] *= 2;
                            game[row][ccol] = 0;
                        }
  
                    }
                }
            }
        }
        break;
    }
  
}
  

int Input()
{
    cout << "Enter direction (w=UP, s=DOWN, a=LEFT, d=RIGHT): ";
    char input;
    cin >> input; // Blocking waiting for user input

    switch (input)
    {
    case 'w': return UP;
    case 's': return DOWN;
    case 'a': return LEFT;
    case 'd': return RIGHT;
    default:
        cout << "Invalid input. Please use w, a, s, d." << endl;
        return 0; // Indicates invalid input
    }
}

//Judgement of game status
int Judge()
{
    //win
    for(int i = 0; i < ROW; ++i)
    {
        for(int j = 0; j < COL; ++j)
        {
            if(game[i][j] == 2048)
            {
                return GAME_WIN;
                break;
            }
        }
    }
  
    //Cross-checking
    for(int i = 0 ; i < ROW; ++i)
    {
        for(int j = 0; j < COL - 1; ++j)
        {
            if(!game[i][j] || (game[i][j] == game[i][j+1]))
            {
                return GAME_CONTINUE;
                break;
            }
        }
    }
    //Vertical check
    for(int j = 0; j< COL; ++j)
    {
        for(int i = 0; i < ROW -1; ++i)
        {
            if(!game[i][j] || (game[i][j] == game[i+1][j]))
            {
                return GAME_CONTINUE;
                break;
            }
        }
    }
  
    //Does not meet either of these conditions. Game over.
    return GAME_OVER;
  
}
  
int main() {
    cout << "Enter w, s, a, d to start and count down 2 minute." << endl;
    srand((unsigned int)time(0));
    CreateNumber();
    CreateNumber();
    auto start = std::chrono::system_clock::now();

    int direction = 0;
    int gameState = -1;
    while (true) {
        direction = Input();
        gameState = Judge();

        auto now = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = now - start;

        if (elapsed_seconds.count() >= 120) { // 120s
            cout << "Time's up! Game over. QQ" << endl;
            gameState = GAME_OVER;
            break; // End game loop
        }

        if (direction && gameState == GAME_CONTINUE) {
            Process(direction);
            CreateNumber();
            Print(elapsed_seconds); // Pass the time difference as a parameter to Print
            usleep(100 * 1000);
        } else if (gameState == GAME_WIN) {
            Print(elapsed_seconds);
            cout << "Win！！！！" << endl;
            break;
        } else if (gameState == GAME_OVER) {
            Print(elapsed_seconds); 
            cout << "Lose,QQ" << endl;
            break;
        }
    }

    return 0;
}
