/**
 * Problem    : 3027
 * Difficulty : Hard
 * Language   : C
 * Status     : Incomplete
 */

#include <stdio.h>
#include <stdlib.h>

int numberOfPairs(int** points, int pointsSize, int* pointsColSize) {
    return 0;
}

int main() {
    int pointsSize = 3;
    int* pointsColSize = malloc(pointsSize * sizeof(int));
    int** points = malloc(pointsSize * sizeof(int*));

    int temp[3][2] = {
        {6, 2},
        {4, 4},
        {2, 6}
    };

    for(int i = 0; i < pointsSize; i++) {
        pointsColSize[i] = 2;
        points[i] = malloc(pointsColSize[i] * sizeof(int));
        for(int j = 0; j < pointsSize; j++) {
            points[i][j] = temp[i][j];
        }
    }

    int num_pairs = numberOfPairs(points, pointsSize, pointsColSize);
    printf("Number of pairs = %i", num_pairs);

    for(int i = 0; i < pointsSize; i++)
        free(points[i]);

    free(points);
    free(pointsColSize);

    return 0;
}
