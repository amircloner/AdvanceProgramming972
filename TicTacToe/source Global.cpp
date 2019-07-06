#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
using namespace std;
int playerChoice;
int gameWin = 3;

char blockOne = '1';
char blockTwo = '2';
char blockThree = '3';
char blockFour = '4';
char blockFive = '5';
char blockSix = '6';
char blockSeven = '7';
char blockEight = '8';
char blockNine = '9';

void checkWinComputer()
{
    if(blockOne == 'O' && blockFive == 'O' && blockNine == 'O' )
        gameWin = 2;
    if(blockThree == 'O' && blockFive == 'O' && blockSeven == 'O' )
        gameWin = 2;
    if(blockOne == 'O' && blockTwo == 'O' && blockThree == 'O' )
        gameWin = 2;
    if(blockFour == 'O' && blockFive == 'O' && blockSix == 'O' )
        gameWin = 2;
    if(blockSeven == 'O' && blockEight == 'O' && blockNine == 'O' )
        gameWin = 2;
    if(blockOne == 'O' && blockFour == 'O' && blockSeven == 'O' )
        gameWin = 2;
    if(blockTwo == 'O' && blockFive == 'O' && blockEight == 'O')
        gameWin = 2;
    if(blockThree == 'O' && blockSix == 'O' && blockNine == 'O')
        gameWin = 2;
}
void checkWinPlayer()
{
    if(blockOne == 'X' && blockFive == 'X' && blockNine == 'X')
        gameWin = 1;
    if(blockThree == 'X' && blockFive == 'X' && blockSeven == 'X' )
        gameWin = 1;
    if(blockOne == 'X' && blockTwo == 'X' && blockThree == 'X' )
        gameWin = 1;
    if(blockFour == 'X' && blockFive == 'X' && blockSix == 'X' )
        gameWin = 1;
    if(blockSeven == 'X' && blockEight == 'X' && blockNine == 'X' )
        gameWin = 1;
    if(blockOne == 'X' && blockFour == 'X' && blockSeven == 'X')
        gameWin = 1;
    if(blockTwo == 'X' && blockFive == 'X' && blockEight == 'X')
        gameWin = 1;
    if(blockThree == 'X' && blockSix == 'X' && blockNine == 'X')
        gameWin = 1;
}
void computerChoice()
{
    srand(time(NULL));

    while(1){

        int a=0;
		a=rand()% 9 +1;

        if (a==1 && blockOne == '1' )
        {
            blockOne = 'O';
			break;
        }
         if (a==2 && blockTwo == '2' )
        {
            blockTwo = 'O';
			break;
        }
         if (a==3 && blockThree == '3' )
        {
            blockThree = 'O';
			break;
        }
         if (a==4 && blockFour == '4' )
        {
            blockFour = 'O';
			break;
        }
        else if (a==5 && blockFive == '5' )
        {
            blockFive = 'O';
			break;
        }
         if (a==6 && blockSix == '6' )
        {
            blockSix = 'O';
			break;
        }
         if (a==7 && blockSeven == '7' )
        {
            blockSeven = 'O';
			break;
        }
         if (a==8 && blockEight == '8' )
        {
            blockEight = 'O';
			break;
        }
        if (a==9 && blockNine == '9' )
        {
            blockNine = 'O';
			break;
        }
	}
}

void checkPlayerInput()
{
    if(playerChoice == 1 && blockOne == '1')
        blockOne = 'X';
    if(playerChoice == 2 && blockTwo == '2')
        blockTwo = 'X';
    if(playerChoice == 3 && blockThree == '3')
        blockThree = 'X';
    if(playerChoice == 4 && blockFour == '4')
        blockFour = 'X';
    if(playerChoice == 5 && blockFive == '5')
        blockFive = 'X';
    if(playerChoice == 6 && blockSix == '6')
        blockSix = 'X';
    if(playerChoice == 7 && blockSeven == '7')
        blockSeven = 'X';
    if(playerChoice == 8 && blockEight == '8')
        blockEight = 'X';
    if(playerChoice == 9 && blockNine == '9')
        blockNine = 'X';
}

void checkPlayerInputO()
{
    if(playerChoice == 1 && blockOne == '1')
        blockOne = 'O';
    if(playerChoice == 2 && blockTwo == '2')
        blockTwo = 'O';
    if(playerChoice == 3 && blockThree == '3')
        blockThree = 'O';
    if(playerChoice == 4 && blockFour == '4')
        blockFour = 'O';
    if(playerChoice == 5 && blockFive == '5')
        blockFive = 'O';
    if(playerChoice == 6 && blockSix == '6')
        blockSix = 'O';
    if(playerChoice == 7 && blockSeven == '7')
        blockSeven = 'O';
    if(playerChoice == 8 && blockEight == '8')
        blockEight = 'O';
    if(playerChoice == 9 && blockNine == '9')
        blockNine = 'O';
}

void checkComputerInput(int computerPick)
{
    if(computerPick == 1 && blockOne == '1')
        blockOne = 'O';
    if(computerPick == 2 && blockTwo == '2')
        blockTwo = 'O';
    if(computerPick == 3 && blockThree == '3')
        blockThree = 'O';
    if(computerPick == 4 && blockFour == '4')
        blockFour = 'O';
    if(computerPick == 5 && blockFive == '5')
        blockFive = 'O';
    if(computerPick == 6 && blockSix == '6')
        blockSix = 'O';
    if(computerPick == 7 && blockSeven == '7')
        blockSeven = 'O';
    if(computerPick == 8 && blockEight == '8')
        blockEight = 'O';
    if(computerPick == 9 && blockNine == '9')
        blockNine = 'O';
}

void gameBoard()
{
    cout << "|-----|-----|-----|" << endl;
    cout << "|  " <<blockOne << "  |  " << blockTwo << "  |  " << blockThree << "  |" << endl;
    cout << "|-----|-----|-----|" << endl;
    cout << "|  " <<blockFour << "  |  " << blockFive << "  |  " << blockSix << "  |" << endl;
    cout << "|-----|-----|-----|" << endl;
    cout << "|  " <<blockSeven << "  |  " << blockEight << "  |  " << blockNine << "  |\n";
    cout << "|-----|-----|-----|" << endl;
}

void checkTie()
{
    if(blockOne != '1' && blockTwo != '2' && blockThree != '3' && blockFour != '4' && blockFive != '5' && blockSix != '6' && blockSeven != '7' && blockEight != '8' && blockNine != '9' && gameWin==3)
    {
        gameWin = 0;
    }
}

int main()
{
    srand(time(0));
    int playAgain;

    int playerScore = 0;
    int computerScore = 0;
    int noWinner = 0;
    int comfri=0;
    cout<<"PLAY WITH COMPUTER OR PLAY WITH FRIEND?\n 1.COMPUTER \n 2.FRIEND \n";
    cin>>comfri;
    if(comfri==1)
    {
        do
        {
            system("CLS");
            int computerRandomPick = rand()% (9 - 1 + 1)+1;
            gameWin = 3;
            blockOne = '1';
            blockTwo = '2';
            blockThree = '3';
            blockFour = '4';
            blockFive = '5';
            blockSix = '6';
            blockSeven = '7';
            blockEight = '8';
            blockNine = '9';

            cout << "Welcome to Dooz!" <<endl<< endl;
            cout << "Player: " << playerScore << " Computer: "<< computerScore << " NO Winner: " << noWinner << endl;

                int computerPick = computerRandomPick;
                checkComputerInput(computerPick);
                cout << "The computer choosed...\n" << endl;
                gameBoard();

            do
            {

                    cout << "Please choose a scope to place (X): "<<endl<<endl;
                    while (!(cin >> playerChoice))
                    {
                        cout << endl;
                        cout << "Numbers only." << endl;
                        cin.clear();
                        cin.ignore(10000,'\n');
                    }
                    checkPlayerInput();
                    checkWinPlayer();
                    checkTie();



                    computerChoice();
                    system("CLS");
                    gameBoard();
                    checkWinComputer();
                    checkTie();

            }
            while(gameWin > 2);

            if(gameWin == 0)
            {
                cout << "The game doesn't have winner!" << endl;
                ++noWinner;
            }

            if(gameWin == 1)
            {
                cout << "The Human player wins!" << endl;
                ++playerScore;
            }

            if(gameWin == 2)
            {
                cout << "The computer wins!" << endl;
                ++computerScore;
            }

            cout << "Player: " << playerScore << " "<< "Computer: " << computerScore << " No Winner: "<< noWinner << endl;

            cout << "Play again?\n1. Yes\n2. No\n" << endl;

            while (!(cin >> playAgain))
            {
                cout << endl;
                cout << "Do You Play again?\n1. Yes\n2. No\n" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
            }
        }
        while(playAgain == 1);

    }
    else
    {
           do
        {
            system("CLS");
            gameWin = 3;

            blockOne = '1';
            blockTwo = '2';
            blockThree = '3';
            blockFour = '4';
            blockFive = '5';
            blockSix = '6';
            blockSeven = '7';
            blockEight = '8';
            blockNine = '9';

            cout << "Welcome to Dooz!" <<endl<< endl;
            cout << "Player X: " << playerScore << " Player O: "<< computerScore << " NO Winner: " << noWinner << endl;

                cout << "Please choose a scope to place (X): "<<endl<<endl;
                gameBoard();
                while (!(cin >> playerChoice))
                {
                    cout << endl;
                    cout << "Numbers only." << endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }
                checkPlayerInput();
                system("CLS");
                gameBoard();

            do
            {
                    cout << "Please choose a scope to place (O): "<<endl<<endl;
                    while (!(cin >> playerChoice))
                    {
                        cout << endl;
                        cout << "Numbers only." << endl;
                        cin.clear();
                        cin.ignore(10000,'\n');
                    }
                    checkPlayerInputO();
                    system("CLS");
                    gameBoard();
                    checkWinComputer();
                    checkTie();


                if(gameWin != 1 && gameWin != 2 && gameWin !=0)
                {
                    cout << "Please choose a scope to place (X): "<<endl<<endl;
                    while (!(cin >> playerChoice))
                    {
                        cout << endl;
                        cout << "Numbers only." << endl;
                        cin.clear();
                        cin.ignore(10000,'\n');
                    }
                    checkPlayerInput();
                    system("CLS");
                    gameBoard();
                    checkWinPlayer();
                    checkTie();
                }
            }
            while(gameWin > 2);

            if(gameWin == 0)
            {
                cout << "The game doesn't have winner!!" << endl;
                ++noWinner;
            }
            if(gameWin == 1)
            {
                cout << "The player X wins!" << endl;
                ++playerScore;
            }
            if(gameWin == 2)
            {
                cout << "The player O wins!" << endl;
                ++computerScore;
            }
            cout << "player X: " << playerScore << " "<< "player O: " << computerScore << " NO Winner: "<< noWinner << endl;

            cout << "Play again?\n1. Yes\n2. No\n" << endl;

            while (!(cin >> playAgain))
            {
                cout << endl;
                cout << "Play again?\n1. Yes\n2. No\n" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
            }
        }
        while(playAgain == 1);
    }
    return 0;
}

///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@///
///@@ (C) Copyright 1999-2019 by AMIR MOHSENINIA All Rights Reserved.      @@//
///@@     visit my github page : github.com/amircloner                     @@//
///@@                                                                      @@//
///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@///
