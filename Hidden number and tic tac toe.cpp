#include <iostream>
using namespace std;

class Game
{
public:
    int targetNumber;

    Game()
    {
        targetNumber = 95;
    }

    virtual ~Game() {}

    void play()
    {
        cout << "Welcome to the Hidden Number Detection Game!" << endl;
        cout << "You have 10 attempts to guess the hidden number between 1 and 100." << endl;

        int attempts = 0;
        int guess = 0;

        do
        {
            cout << "Attempt " << attempts + 1 << ": Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess < targetNumber)
            {
                cout << "Too low! Try again." << endl;
            }
            else if (guess > targetNumber)
            {
                cout << "Too high! Try again." << endl;
            }
            else
            {
                cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
                return; // Exit if the guess is correct
            }
        } while (guess != targetNumber && attempts < 10);

        if (guess != targetNumber)
        {
            cout << "You've used all your attempts. The correct number was " << targetNumber << "." << endl;
        }
    }
};

class TicTacToe
{
public:
    char space[3][3];
    int row;
    int column;
    char token;
    bool tie;
    string n1;
    string n2;

    TicTacToe() : row(0), column(0), token('x'), tie(false), n1(""), n2("")
    {
        char initialSpace[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                space[i][j] = initialSpace[i][j];
            }
        }
    }

    void displayBoard()
    {
        cout << "   |   |   \n";
        cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << " \n";
        cout << "___|___|___\n";
        cout << "   |   |   \n";
        cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << " \n";
        cout << "___|___|___\n";
        cout << "   |   |   \n";
        cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << " \n";
        cout << "   |   |   \n";
    }

    void getPlayerInput()
    {
        int digit;
        if (token == 'x')
        {
            cout << n1 << " please enter a number: ";
        }
        else
        {
            cout << n2 << " please enter a number: ";
        }
        cin >> digit;

        if (digit >= 1 && digit <= 9)
        {
            row = (digit - 1) / 3;
            column = (digit - 1) % 3;
        }
        else
        {
            cout << "Invalid input!" << endl;
            return;
        }

        if (space[row][column] != 'x' && space[row][column] != '0')
        {
            space[row][column] = token;
            token = (token == 'x') ? '0' : 'x';
        }
        else
        {
            cout << "This space is already taken. Please try again." << endl;
        }
    }

    bool checkGameResult()
    {
        for (int i = 0; i < 3; i++)
        {
            if ((space[i][0] == space[i][1] && space[i][1] == space[i][2]) ||
                (space[0][i] == space[1][i] && space[1][i] == space[2][i]))
            {
                return true;
            }
        }

        if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
            (space[0][2] == space[1][1] && space[1][1] == space[2][0]))
        {
            return true;
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (space[i][j] != 'x' && space[i][j] != '0')
                {
                    return false;
                }
            }
        }
        tie = true;
        return true;
    }
};

int main()
{
    int choice;
    cout << "Select a game to play (1 for Number Guessing, 2 for Tic-Tac-Toe): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        Game game;
        game.play();
        break;
    }
    case 2:
    {
        TicTacToe ticTacToe;
        cout << "Enter the name of the first player: ";
        cin >> ticTacToe.n1;
        cout << "Enter the name of the second player: ";
        cin >> ticTacToe.n2;
        cout << ticTacToe.n1 << " is player 1, so they will play first." << endl;
        cout << ticTacToe.n2 << " is player 2, so they will play second." << endl;

        while (!ticTacToe.checkGameResult())
        {
            ticTacToe.displayBoard();
            ticTacToe.getPlayerInput();
        }

        ticTacToe.displayBoard();

        if (ticTacToe.tie)
        {
            cout << "It's a draw" << endl;
        }
        else if (ticTacToe.token == '0')
        {
            cout << ticTacToe.n1 << " Wins!!" << endl;
        }
        else
        {
            cout << ticTacToe.n2 << " Wins!!" << endl;
        }
        break;
    }
    default:
        cout << "Invalid choice." << endl;
        break;
    }

    return 0;
}
