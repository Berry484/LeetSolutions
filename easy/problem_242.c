/**
 * Problem    : 242
 * Difficulty : Easy
 * Language   : C
 * Time       : O(n + m)
 * Space      : O(1)
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t);

int main() {
    char s[] = "anagram", t[] = "nagaram";
    printf("isAngagram = %i", isAnagram(s, t));

    printf("\n\n");
    return 0;
}

/**
 * Returns if given string is anagram.
 *
 * @param   s   -String to check if other string is anagram of this.
 * @param   t   -String t to check if is anagram
 *
 * @return if t is an anagram of s.
 */
bool isAnagram(char* s, char* t) {
    int s_size = strlen(s),
        t_size = strlen(t);

    int* s_letters = calloc(26, sizeof(int));

    if (s_size != t_size)
        return false;

    for (int i = 0; i < s_size; i++) {
        s_letters[s[i] - 'a']++;
        s_letters[t[i] - 'a']--;
    }
    
    for (int i = 0; i < s_size; i++) {
        if (s_letters[s[i] - 'a'] != 0)
            return false;
    }

    free(s_letters);
    return true;
}
