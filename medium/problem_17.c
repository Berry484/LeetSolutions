/*
 * Problem    : 17
 * Difficulty : Medium
 * Language   : C
 * Time       : O(4^n\cdot n), n = length of digits string
 * Space      : O(n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* keypad[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(char** result, int* resultSize, char* combination, char* digits, int index) {
    if (digits[index] == '\0') {
        result[*resultSize] = strdup(combination);
        resultSize[0]++;
        return;
    }
    
    const char* letters = keypad[digits[index] - '2'];
    for (int i = 0; letters[i] != '\0'; i++) {
        int len = strlen(combination);
        combination[len] = letters[i];
        combination[len + 1] = '\0';
        backtrack(result, resultSize, combination, digits, index + 1);
        combination[len] = '\0';
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    if (digits[0] == '\0') {
        *returnSize = 0;
        return NULL;
    }

    char** result = malloc(1000 * sizeof(char*));
    *returnSize = 0;
    char combination[100] = "";
    backtrack(result, returnSize, combination, digits, 0);
    return result;
}

int main() {
    char digits[] = "23";
    int returnSize = 0;

    char** combinations = letterCombinations(digits, &returnSize);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("\"%s\"", combinations[i]);
        if (i < returnSize - 1) {
            printf(",");
        }
        free(combinations[i]);  
    }
    printf("]\n");

    free(combinations);
    return 0;
}
