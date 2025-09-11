/**
 * Problem    : 2785
 * Difficulty : Medium
 * Language   : C
 * Time       : O(n*log(n))
 * Space      : O(n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char* sortVowels (char* s);
bool isVowel (char s);
int cmpfunc (const void *a, const void *b);

/*
 * Main program.
 */
int main() {
    char s[] = "lEetcOde";
    char* sortedStr = sortVowels(s);

    printf("Sorted vowels: %s", sortVowels(s));
    free(sortedStr);

    printf("\n\n");
    return 0;
}

/**
 * Help function for qsort.
 */
int cmpfunc(const void* a, const void *b) {
    return(*(const char *)a - *(const char *)b);
}

/**
 * Sorts vowels based on ASCII values and consonants remain.
 *
 * @param   s   -String that we want to sort
 *
 * @return string that are now sorted.
 */
char* sortVowels(char* s) {
    int tempSize = 0,
        size = strlen(s);

    char* temp = malloc(size + 1);

    for(int i = 0; i < size; i++) {
        if (isVowel(s[i])) {
            temp[tempSize] = s[i];
            tempSize++;
        }
    }
    temp[tempSize] = '\0';

    qsort(temp, tempSize, sizeof(char), cmpfunc);

    int j = 0;
    char* ans = malloc(size + 1);

    for(int i = 0; i < size; i++) {
        if(isVowel(s[i])) {
            ans[i] = temp[j];
            j++;
        }
        else
            ans[i] = s[i];
    }
    ans[size] = '\0';

    free(temp);
    return ans;
}


/**
 * Tells wether a char is a vowel or not.
 *
 * @param   s   -Char that we want to check for vowel.
 *
 * @return true/false if s is a vowel
 */
bool isVowel(char s) {
    char vowels[] = "aeiou";

    for(int i = 0; i < 5; i++) {
        if(tolower(s) == vowels[i])
            return true;
    }

    return false;
}
