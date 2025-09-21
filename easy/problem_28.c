/**
 * Problem    : 28
 * Difficulty : Easy
 * Language   : C
 * Time       : O(n * m)
 * Space      : O(1)
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int strStr(char* hayStack, char* needle);

int main() {
    char haystack[] = "leetcode", needle[] = "leeto";
    int index = strStr(haystack, needle);
    printf("Index of first occurence = %i", index);

    printf("\n\n");
    return 0;
}

/**
 * Returns the index of first occurence of needle in haystack.
 *
 * @param   haystack    -Char-array that contains haystack
 * @param   needle      -Char-array that has the string we want to search for
 *
 * @return the index of first occurence.
 */
int strStr(char* haystack, char* needle) {
    int needle_s = strlen(needle),
        haystack_s = strlen(haystack);

    bool match = true;

    
    for (int i = 0; i < haystack_s; i++) {
        if (haystack[i] == needle[0]) {
            match = true;
            for (int j = 0; j < needle_s; j++) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                return i;
        }

    }

    return -1;
}
