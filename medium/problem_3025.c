/*
 * Problem    : 3025
 * Difficulty : Medium
 * Language   : C
 * Time       : O(n^2)
 * Space      : O(n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int x;
    int y;
} pair;

int compare(const void* p1,const void* p2) {
    pair* a = (pair*)p1;
    pair* b = (pair*)p2;

    if(a->x!=b->x)
        return a->x-b->x;
    else
        return b->y-a->y;
}

int numberOfPairs(int** points, int pointsSize, int* pointsColSize) {
    int num_pairs = 0,
        x = 0,
        y = 0;

    pair* list = (pair*)malloc(pointsSize * sizeof(pair));
    
    for(int i = 0; i < pointsSize; i++) {
        list[i].x = points[i][0];
        list[i].y = points[i][1];
    }
    qsort(list, pointsSize, sizeof(pair), compare);

    for(int i = 0; i < pointsSize; i++) {
        y = INT_MIN;
        for(int j = i + 1; j < pointsSize; j++) {
            if(list[i].y >= list[j].y && y < list[j].y) {
                y=list[j].y;
                num_pairs++;
            }
        }
    }

    free(list);
    return num_pairs;
}

int main() {
    int pointsSize = 3;
    int* pointsColSize = malloc(2 * sizeof(int));
    int** points = malloc(pointsSize * sizeof(int*));

    int temp[3][2] = {
        {6, 2},
        {4, 4},
        {2, 6}
    };

    for(int i = 0; i < pointsSize; i++) {
        pointsColSize[i] = 2;
        points[i] = malloc(pointsColSize[i] * sizeof(int));
        for(int j = 0; j < pointsColSize[i]; j++)
            points[i][j] = temp[i][j];
    }


    int num_pairs = numberOfPairs(points, pointsSize, pointsColSize);
    printf("Pairs = %i\n\n", num_pairs);

    for(int i = 0; i < pointsSize; i++)
        free(points[i]);

    free(points);
    free(pointsColSize);

    return 0;
}
