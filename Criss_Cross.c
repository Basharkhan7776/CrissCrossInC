#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void printBoard(char board[ROWS][COLS]) 
{
    for (int i = 0; i < ROWS; i++)
     {
        for (int j = 0; j < COLS; j++) 
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWinner(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
        {
            return 1;
        }
    }
    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) 
        {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
    {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
    {
        return 1;
    }
    return 0;
}

int main() {
    char board[ROWS][COLS] = {{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}};

    int turn = 0;
    while (1) {
        system("clear");
        printBoard(board);
        printf("\nTurn for player %c: ", turn % 2 == 0 ? 'X' : 'O');
        int choice;
        scanf("%d", &choice);
        if (choice < 1 || choice > 9) 
        {
            printf("\nInvalid choice. Please choose between 1 and 9.");
            getchar();
            continue;
        }
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        if (board[row][col] != '1' + row * 3 + col) 
        {
            printf("\nThis cell is already occupied. Please choose another cell.");
            getchar();
            continue;
        }
        board[row][col] = turn % 2 == 0 ? 'X' : 'O';
        if (checkWinner(board)) 
        {
            printf("\nCongratulations! Player %c wins!", turn % 2 == 0 ? 'X' : 'O');
            break;
        }
        turn++;
        getchar();
    }

    return 0;
}