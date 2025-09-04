/**
 * Problem    : 7
 * Difficulty : Medium
 * Language   : C
 * Time       : O(n)
 * Space      : O(1)
 */

#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    long long rev_val = 0;
    int last_num;

    while(x != 0) {
        last_num = x % 10;
        rev_val = rev_val * 10 + last_num;

        if(rev_val > INT_MAX || rev_val < INT_MIN)
            return 0;

        x /= 10;
    }


    return (int)rev_val;
}

int main(void) {
    int x = 123;
    
    printf(" %i reversed is %i\n\n", x, reverse(x));

    return 0;
}

