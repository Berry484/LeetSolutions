/**
 * Problem    : 3110
 * Difficulty : Easy
 * Language   : C
 * Time       : O(n)
 * Space      : O(1)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scoreOfString(char* s) {
    int score = 0;
    int size = strlen(s);

    for(int i = 0; i < size - 1; i++) {
        int char_1 = (int)s[i];
        int char_2 = (int)s[i + 1];
        score += abs(char_1 - char_2);
    }

    return score;
}

int main() {
    char* s = "hello";
    int score = scoreOfString(s);
    printf("The score = %i", score);

    return 0;
}
