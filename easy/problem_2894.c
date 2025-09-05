/**
 * Problem    : 2894
 * Difficulty : Easy
 * Language   : C
 * Time       : O(n)
 * Space      : O(1)
 */

#include <stdio.h>

int differenceOfSums(int n, int m) {
    int num1 = 0, num2 = 0;

    for(int i = 1; i <= n; i++) {
        if(i % m == 0)
           num2 += i;

        else
            num1 += i;
    }

    return num1 - num2;
}

int main() {
    int n = 10, m = 3;
    int diff = differenceOfSums(n, m);
    printf("The num1 - num2 = %i", diff);

    return 0;
}
