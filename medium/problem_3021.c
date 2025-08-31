/*
 * Problem    : 3021
 * Difficulty : Medium
 * Language   : C
 * Time       : O(1)
 * Space      : O(1)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long flowerGame(int n, int m) {   
    return (long long) n * m / 2;
}

int main() {
    int n = 3,
        m = 3,
        output = 0;
    output = flowerGame(n, m);
    printf("\nOutput = %i\n\n", output);

    return 0;
}
