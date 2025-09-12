/*
 * Problem    : 3227
 * Difficulty : Medium
 * Language   : C
 * Time       : O(n^2)
 * Space      : O(1)
 */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool doesAliceWin (char* s);
bool isVowel (char c);

/**
 * Main program.
 */
int main() {
    char s[] = "leetcoder";
    printf("Alice win = %i\n\n", doesAliceWin(s));
    return 0;
}

/**
 * Checks if char is a vowel.
 *
 * @param   c   -Char to check.
 *
 * @return if char is a vowel.
 */
bool isVowel(char c) {
    char vowels[] = "aeiou";
    for(int i = 0; i < 5; i++)
        if(tolower(c) == vowels[i])
            return true;

    return false;
}

/**
 * Checks if alice wins turn based game.
 *
 * @param   s   -Char-array tha contains string to check
 *
 * @return if Alice won or not.
 */
bool doesAliceWin(char* s) {
    int size = strlen(s);
    for(int i = 0; i < size; i++)
        if(isVowel(s[i]))
            return true;

    return false;
}
