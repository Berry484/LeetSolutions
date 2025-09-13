/**
 * Problem    : 3541
 * Difficulty : Easy
 * Language   : C
 * Time       : O(n)
 * Space      : O(26)
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int maxFreqSum (char* s);
bool isVowel(char c);

/**
 * Main program.
 */
int main() {
    char s[] = "successes";
    printf("Max freq = %i\n\n", maxFreqSum(s));

    return 0;
}

/**
 * Returns wether a char is a vowel or not.
 *
 * @param   c   -char we check if is a vowel.
 *
 * @returns if char is a vowel.
 */
bool isVowel(char c) {
    char vowels[] = "aeiou";
    
    for(int i = 0; i < 5; i++)
        if(c == vowels[i])
            return true;

    return false;
}

/**
 * Returns frequency of vowels and constants.
 *
 * @param   s   -char-array that contains string.
 *
 * @return frequency of vowel and constant.
 */
int maxFreqSum(char* s) {
    int mp[26] = {0};
    for(int i = 0; s[i] != '\0'; i++)
        mp[s[i] - 'a']++;

    int vowel = 0, consonant = 0;
    for(char ch = 'a'; ch <= 'z'; ch++) {
        if (isVowel(ch))
            vowel = fmax(vowel, mp[ch - 'a']);
        else
            consonant = fmax(consonant, mp[ch - 'a']);
    }

    return vowel + consonant;
}
