/**
 * Problem    : 2749
 * Difficulty : Medium
 * Language   : C
 * Time       : O(1)
 * Space      : O(1)
 */

#include <stdio.h>
#include <stdlib.h>

int makeTheIntegerZero(int num1, int num2) {
    for (long long k = 1; k <= 60; k++) {
        long long X = (long long)num1 - k * (long long)num2;
        if (X >= 0) {
            int bits = __builtin_popcountll(X);
            if (bits <= k && k <= X) {
                return (int)k;
            }
        }
    }
    return -1;
}

int main() {
    int num1 = 3, num2 = -2;
    int output = makeTheIntegerZero(num1 ,num2);
    printf("Minimal operations is: %i", output);

    return 0;
}
