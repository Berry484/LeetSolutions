/**
 * Problem    : 8
 * Difficulty : Medium
 * Language   : C
 * Time       : O(n)
 * Space      : O(1)
 */

#include <stdio.h>
#include <limits.h>

int myAtoi(char* s) {
    int read_start = 0,
        negative = 0,
        start_read = 0;

    long long val = 0;
    

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == '-' && !start_read)
            start_read = 1, negative = 1;
        
        else if(s[i] == '+' && !start_read)
            start_read = 1;

        else if(s[i] >= '0' && s[i] <= '9') {
            start_read = 1;
            read_start = s[i] - '0';
            val *= 10;
            val += read_start;

            if(!negative && val > INT_MAX)
                return INT_MAX;

            if(negative && -val < INT_MIN)
                return INT_MIN;
        }

        else if(s[i] != ' ' || start_read)
            break;
    }

    if(negative == 1)
        val *= -1;

    return val;
}



int main() {
    char test1[] = "42";
    char test2[] = "-042";
    char test3[] = "1337c0d3";
    char test4[] = "0-1";
    
    printf("String [%i] = %i\n", 1, myAtoi(test1));
    printf("String [%i] = %i\n", 2, myAtoi(test2));
    printf("String [%i] = %i\n", 3, myAtoi(test3));
    printf("String [%i] = %i\n\n", 4, myAtoi(test4));

    return 0;
}
