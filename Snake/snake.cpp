#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h> // To make spawn value more random
using namespace std;

bool gameOver;//define gameover to show when the while loop has been exit

const int width = 20;//set the width of the map
const int height = 20;//set the height of the map

int x,y;//two variable to determine head position of snake
int foodX,foodY;//two variable to determine position of food
int deathX, deathY;

int score=0;

int tailX[100], tailY[100];
int nTail;

enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};//to define(dade shomaresh)(e.g.) 0=stop 1=left 2=right 3=up 4=down
eDirecton dir;

void Setup()//to determine place of random food,death,and first head of snake
{
    gameOver = false;
    dir = STOP;//so snake will not moving while you moving it
    x = width/2;
    y = height/2;
    //set position of the food
	srand(time(0));//to NULL time of random function
    foodX = rand() % width;
    foodY = rand() % height;

	while(1)
	{
		srand(time(0));
		deathX = rand() % width;
		deathY = rand() % height;
		if(!(deathX==foodX && deathY==foodY))
			break;
	}
    score = 0;
}
/*
#############
#        *  #
#   @       #
#           #
#     O     #
#           #
#           #
#############
*/
void Draw()//to draw game board
{
    system("cls");//to clear screen before draw the gameboard
    //# surrounded the 20*20 roadmap for this reason we add +2 to width(2 character for wall)
	for (int j = 0; j < width+2; j++)
		cout << "#";
		cout << endl;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (j == 0)
					cout << "#";//print first of line #
                if (i == y && j == x)
                    cout << "O";
               else if (i == deathY && j == deathX)
                    cout << "*";
               else if (i == foodY && j == foodX)
                    cout << "@";
                else
                {
                    bool print = false;
                    for (int k = 0; k < nTail; k++)
                    {
                        if (tailX[k] == j && tailY[k] == i)
                        {
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print)
                        cout << " ";
                }

                if (j == width- 1)
					cout << "#";
            }
            cout << endl;//to add next line to start new line by close for
        }

    for (int j = 0; j < width+2; j++)
		cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}
void Input()//to input from keyboard set the movement of snake
{
    if (_kbhit())
    {
        char ch=_getch();
        switch (ch)
        {
            case 75:
                dir = LEFT;
                break;
            case 77:
                dir = RIGHT;
                break;
            case 72:
                dir = UP;
                break;
            case 80:
                dir = DOWN;
                break;
            case 13:
                gameOver = true;
                break;
            default:
                break;
        }
    }
}
void Logic()
{
    int previousX = tailX[0];
    int previousY = tailY[0];
    int previous2X, previous2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        previous2X = tailX[i];
        previous2Y = tailY[i];
        tailX[i] = previousX;
        tailY[i] = previousY;
        previousX = previous2X;
        previousY = previous2Y;
    }
    //to set direction of the snake with increase or decrease positon of the head
    switch (dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    //if snake  the wall conduct gameover
    if (x > width || x < 0 || y > height || y < 0)
      gameOver = true;
    //if head of snake conduct tail gameover
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = false;
    //this scope i set the hole to gameover if O=* gmaeover
    if (x == deathX && y == deathY)
	{
		gameOver= true;
	}
	else if(x == foodX && y == foodY)//if the snake eat the food i change the position of the HOLE
    {
		while(1)
		{
			srand(time(0));
			deathX = rand() % width;
			deathY = rand() % height;
			if(!(deathX==foodX && deathY==foodY))//to not equal position of the Hole and food
				break;
		}
    }
	else
	{
		deathX;
		deathY;
	}
    //if snake eat the food tail++ and change the position of the food
    if (x == foodX && y == foodY)
    {
        score += 10;
		while(1)
		{
			srand(time(0));
			foodX = rand() % width;
			foodY = rand() % height;
			if(!(deathX==foodX && deathY==foodY))
				break;
		}
        nTail++;
    }
}
int main()
{
    int playAgain;
     do{
        nTail=0;
        score=0;
    system("cls");
    int level;
    cout<<"Please choose your level game: \n 1.easy \n 2.medium \n 3.hard \n 4.custom"<<endl;
    cin>>level;
    switch(level)//i use the swith to set level of the game
    {
        case 1:
            {
                Setup();
                while (!gameOver)
                    {
                        Draw();
                        Input();
                        Logic();
                        Sleep(120); //to control the speed of the snake
                    }
                 break;
            }
        case 2:
            {
             Setup();
                while (!gameOver)
                    {
                        Draw();
                        Input();
                        Logic();
                        Sleep(85);//to control the speed of the snake
                    }
                 break;
            }
        case 3:
            {
             Setup();
                while (!gameOver)
                    {
                        Draw();
                        Input();
                        Logic();
                        Sleep(50);//to control the speed of the snake
                    }
                 break;
            }
        case 4:
        {
            int custom;
            cout<<"please enter speed of sanke"<<endl;
            cin>>custom;
            {
             Setup();
                while (!gameOver)
                    {
                        Draw();
                        Input();
                        Logic();
                        Sleep(custom);//to control the speed of the snake
                    }
                 break;
            }
        }
        default:
            break;
    }
				system("cls");
				cout<<"        Game Over !!!"<<" score: "<<score<<endl;
                cout << "Play again?\n1. Yes\n2. No\n" << endl;

            while (!(cin >> playAgain))
            {
                cout << endl;
                cout << "Do You Play again?\n1. Yes\n2. No\n" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
            }
        }while(playAgain == 1);
    return 0;
}

///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@///
///@@     written by AMIR MOHSENINIA No Rights Reserved.                   @@//
///@@     visit my github page : github.com/amircloner                     @@//
///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@///
