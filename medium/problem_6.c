/**
 * Problem    : 6
 * Difficulty : Medium
 * Language   : C
 * Time       : O(n)
 * Space      : O(n * numRows)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);
    char row[numRows][len];
    int* rowSizes = calloc(numRows, sizeof(int));
    
    int goingDown = 1;
    int n = 0;

    if(numRows == 1)
        return s;

    for(int i = 0; i < len; i++) {
        row[n][rowSizes[n]] = s[i];
        rowSizes[n]++;
        
        if(n == numRows - 1) goingDown = 0;
        if(goingDown == 0 && n == 0) goingDown = 1;

        if(goingDown)
            n++;
        else
            n--;
    }
    

    char* answer = malloc(len + 1);
    int size = 0;

    for(int i = 0; i < numRows; i++){
        for(int c = 0; c < rowSizes[i]; c++) {
            answer[size++] = row[i][c];
        }
    }

    answer[size] = '\0';
    free(rowSizes);
    return answer;
}

int main(void){
    int numRows = 4;
    char s[] = "PAYPALISHIRING";

    char* answer = convert(s, numRows);

    printf(" %s", answer);
    return 0;
}
