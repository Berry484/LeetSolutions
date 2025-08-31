/*
 * Problem    : 37
 * Difficulty : Hard
 * Language   : C
 * Time       : O(9^n), n = number of empty cells
 * Space      : O(1)
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char** board, int row, int col, char ch) {
    for (int i = 0; i < 9; i++) {
        if (ch == board[i][col]) {
            return false;
        }
        if (ch == board[row][i]) {
            return false;
        }
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) {
            return false;
        }
    }

    return true;
}

bool solve(char** board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char k = '1'; k <= '9'; k++) {
                    if (isValid(board, i, j, k)) {
                        board[i][j] = k;
                        if (solve(board)) {
                            return true;
                        } else {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board);
    return;
}


int main() {
    int boardSize = 9;
    int* boardColSize = malloc(boardSize * sizeof(int));
    char** board = malloc(boardSize * sizeof(char*));

    char temp_grid[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    for(int i = 0; i < boardSize; i++)
        boardColSize[i] = boardSize;

    for(int i = 0; i < boardSize; i++) {
        board[i] = malloc(boardColSize[i]);
        for(int j = 0; j < boardSize; j++) {
            board[i][j] = temp_grid[i][j];
        }
    }

    solveSudoku(board, boardSize, boardColSize);
    printf("Sudoku is now soled.\n\n");

    free(boardColSize);
    for(int i = 0; i < boardSize; i++)
        free(board[i]);
    free(board);
    
    return 0;
}
