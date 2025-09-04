/**
 * Problem    : 36
 * Difficulty : Medium
 * Language   : C
 * Time       : O(n^2)
 * Space      : O(1)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int digit = 0;

    for(int i = 0; i < boardSize; i++) {
        bool row_seen[10] = {false},
             col_seen[10] = {false};

        for(int j = 0; j < boardSize; j++) {
            if(board[j][i] != '.') {
                digit = board[j][i] - '0';
                if(col_seen[digit] == true) return false;
                col_seen[digit] = true;
            }

            if(board[i][j] != '.') {
                digit = board[i][j] - '0';
                if(row_seen[digit] == true)return false;
                row_seen[digit] = true;
            }
        }
    }

    for (int boxRow = 0; boxRow < 3; boxRow++) {
        for (int boxCol = 0; boxCol < 3; boxCol++) {
            bool seen[10] = {false};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int r = boxRow * 3 + i;
                    int c = boxCol * 3 + j;
                    if (board[r][c] != '.') {
                        int digit = board[r][c] - '0';
                        if (seen[digit]) return false;
                        seen[digit] = true;
                    }
                }
            }
        }
    }

    return true;
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

    bool is_valid = isValidSudoku(board, boardSize, boardColSize);
    printf("Sudoku is_valid = %i\n\n", is_valid);

    free(boardColSize);
    for(int i = 0; i < boardSize; i++)
        free(board[i]);
    free(board);
    
    return 0;
}
