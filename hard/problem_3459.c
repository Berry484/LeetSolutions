/*
 * Problem    : 3459
 * Difficulty : Hard
 * Language   : C
 * Status     : Incomplete
 */

#include <stdio.h>
#include <stdlib.h>

int lenOfVDiagonal(int** grid, int gridSize, int* gridColSize) {
    
    return 0;
}


int main() {
    int gridSize = 5;
    int gridColSize[5] = {5, 5, 5, 5, 5};
    int** grid = malloc(gridSize * sizeof(int*));
    
    for(int i = 0; i < gridSize; i++) {
        grid[i] = malloc(gridColSize[i] * sizeof(int));
    }

    int tempGrid[5][5] = {
        {2, 2, 1, 2, 2},
        {2, 0, 2, 2, 0},
        {2, 0, 1, 1, 0},
        {1, 0, 2, 2, 2},
        {2, 0, 0, 2, 2}
    };

    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < gridSize; j++) {
            grid[i][j] = tempGrid[i][j];
        }
    }

    printf("Longest v-shaped diagonal is: %i\n\n", lenOfVDiagonal(grid, gridSize, gridColSize));

    for(int i = 0; i < gridSize; i++)
        free(grid[i]);

    free(grid);

    return 0;
}
