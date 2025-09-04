/**
 * Problem    : 3000
 * Difficulty : Easy
 * Language   : C
 * Time       : O(n)
 * Space      : O(1)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int areaOfMaxDiagonal(int** dimensions, int dimensionsSize, int* dimensionsColSize) {
    int l = 0,
        b = 0,
        area = 0,
        max_area = 0,
        diag_i = 0;

    double
        diag = 0,
        diag_val = 0;

    for(int i = 0; i < dimensionsSize; i++) {
        l = dimensions[i][0];
        b = dimensions[i][1];
        
        area = l * b;
        diag = sqrt(l * l + b * b);

        if (diag > diag_val || (diag == diag_val && area > max_area)) {
            max_area = area;
            diag_val = diag;
            diag_i = i;
        }
    }

    return max_area;
}

int main(void) {
    int dimensionsSize = 2;
    int* dimensionsColSize = malloc(dimensionsSize * sizeof(int));

    dimensionsColSize[0] = 2;
    dimensionsColSize[1] = 2;
    
    int** dimensions = malloc(dimensionsSize * sizeof(int*));
    dimensions[0] = malloc(dimensionsColSize[0] * sizeof(int));
    dimensions[1] = malloc(dimensionsColSize[1] * sizeof(int));

    dimensions[0][0] = 9;
    dimensions[0][1] = 3;

    dimensions[1][0] = 6;
    dimensions[1][1] = 8;

    int max_area = areaOfMaxDiagonal(dimensions, dimensionsSize, dimensionsColSize);
    
    free(dimensions[0]);
    free(dimensions[1]);
    free(dimensions);
    free(dimensionsColSize);


    printf("Max area is %i", max_area);
    return 0;
}
