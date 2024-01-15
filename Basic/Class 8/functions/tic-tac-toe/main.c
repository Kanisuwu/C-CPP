#include <stdio.h>
#include <string.h>

void drawnBoard(char board[3][3]) {

    printf("       |       |     \n");
    printf("   %c   |   %c   |   %c  \n", 
            board[0][0], board[0][1], board[0][2]);
    printf("       |       |     \n");
    printf("-------|-------|-------\n");
    printf("       |       |     \n");
    printf("   %c   |   %c   |   %c  \n",
            board[1][0], board[1][1], board[1][2]);
    printf("       |       |     \n");
    printf("-------|-------|-------\n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |   %c  \n",
            board[2][0], board[2][1], board[2][2]);
    printf("       |       |       \n");

}

int readInputRows() {
    int row = 0;
    scanf("%d", &row);
    return row -= 1;
}
int readInputColumns() {
    int column = 0;
    scanf("%d", &column);
    return column -= 1;
}

_Bool isLimit(int row, int column) {
    _Bool isInvalid = 0;
    if (row > 2 || row < 0) isInvalid = 1;
    if (column > 2 || column < 0) isInvalid = 1;
    return isInvalid;
}

void markBoard(char board[3][3], int row, int column, char text) {
    _Bool isInvalid = 0;
    char location = board[row][column];

    while ((location == 'O' || location == 'X') || (isInvalid == 1)) {
        isInvalid = 0;
        printf("Try again.\n");
        row = readInputRows();
        column = readInputColumns();
        location = board[row][column];
        isInvalid = isLimit(row, column);
    }

    board[row][column] = text;
}

char getPoints(char board[3][3]) {
    int xCount, oCount = 0;
    char won = 'N';

    int linesFull = 0;

    int i, j;

    // Checks for vertical lines.
    for (i = 0; i < 3; ++i) {
        xCount = 0;
        oCount = 0;
        for (j = 0; j < 3; ++j) {
            if (board[j][i] == 'X') {
                xCount++;
            }
            if (board[j][i] == 'O') {
                oCount++;
            }
        }
        if (xCount + oCount == 3) {
            linesFull++;
        }
        if (xCount >= 3) {
            won = 'X';
        }
        else if (oCount >= 3) {
            won = 'O';
        }
        else if (linesFull == 3) {
            won = 'D';
        }
    }

    // Checks for horizontal Lines
    for (i = 0; i < 3; ++i) {
        xCount = 0;
        oCount = 0;
        for (j = 0; j < 3; ++j) {
            if (board[i][j] == 'X') {
                xCount++;
            }
            if (board[i][j] == 'O') {
                oCount++;
            }
        }
        if (xCount >= 3) {
            won = 'X';
        }
        else if (oCount >= 3) {
            won = 'O';
        }
    }

    // Checks for diagonal line from left to right;
    for (i = 0; i < 1; ++i) {
        xCount = 0;
        oCount = 0;
        for (j = 0; j < 3; ++j) {
            if (board[j][j] == 'X') {
                xCount++;
            }
            if (board[j][j] == 'O') {
                oCount++;
            }
        }
        if (xCount >= 3) {
            won = 'X';
        }
        else if (oCount >= 3) {
            won = 'O';
        }
    }

    // Diagonal lines from right fo left
    for (i = 0; i < 1; ++i) {
        xCount = 0;
        oCount = 0;
        for (j = 0; j < 3; ++j) {
            if (board[j][2-j] == 'X') {
                xCount++;
            }
            if (board[j][2-j] == 'O') {
                oCount++;
            }
        }
        if (xCount >= 3) {
            won = 'X';
        }
        else if (oCount >= 3) {
            won = 'O';
        }
    }

    return won;
}

_Bool checkForWin(char board[3][3]) {

    _Bool endgame = 0;

    char winner = getPoints(board);

    if (winner == 'X') {
        endgame = 1;
    } 
    else if (winner == 'O') {
        endgame = 1;
    }
    else if (winner == 'D') {
        endgame = 1;
    }
    return endgame;
}

char winMessage(char board[3][3]) {

    char winner = getPoints(board);

    char victory;

    if (winner == 'X') {
        victory = 'X';
    } 
    else if (winner == 'O') {
        victory = 'O';
    }
    else if (winner == 'D') {
        victory = 'D';
    }
    return victory;
}

int main () {

    _Bool endgame = 0;
    int row = 0;
    int column = 0;
    char whoWon;

    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
    };

    while (!endgame) {

        // Player X

        printf("\033[2J\033[H");
        printf("Player X ------- Player O\n");
        drawnBoard(board);

        printf("Player X (Row & Column):\n");
        row = readInputRows();
        column = readInputColumns();

        markBoard(board, row, column, 'X');

        endgame = checkForWin(board);

        if (endgame) {
            whoWon = winMessage(board);
            printf("\033[2J\033[H");
            printf("Player X ------- Player O\n");
            drawnBoard(board);
            if (whoWon == 'O' || whoWon == 'X') {
                printf("Player %c has won!\n", whoWon);
            }
            else {
                printf("Draw. No one won.\n");
            }
            continue;
        }

        // PLayer O

        printf("\033[2J\033[H");
        printf("Player O ------- Player X\n");
        drawnBoard(board);

        printf("Player O (Row & Column):\n");
        row = readInputRows();
        column = readInputColumns();

        markBoard(board, row, column, 'O');

        endgame = checkForWin(board);

        if (endgame) {
            whoWon = winMessage(board);
            printf("\033[2J\033[H");
            printf("Player X ------- Player O\n");
            drawnBoard(board);
            if (whoWon == 'O' || whoWon == 'X') {
                printf("Player %c has won!\n", whoWon);
            }
            else {
                printf("Draw. No one won.\n");
            }
            continue;
        }

    }
    
    return 0;
}
