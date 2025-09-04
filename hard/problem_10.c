/**
 * Problem    : 10
 * Difficulty : Hard
 * Language   : C
 * Time       : O(n^2)
 * Space      : O(1)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMatch(char* s, char* p) {
    bool is_match = false;
    int i = 0;

    while(s[i] != '\0') {
        
        i++;
    }

    return is_match;
}

int main() {
    char* s = malloc(3 * sizeof(char));
    char* p = malloc(3 * sizeof(char));
    char temp_s[] = "ab";
    char temp_p[] = ".*";

    for(int i = 0; i < 2; i++) {
        s[i] = temp_s[i];
        p[i] = temp_p[i];
    }
    s[2] = '\0';
    p[2] = '\0';

    bool match = isMatch(s, p);
    printf("Match = %i\n\n", (int)match);

    free(s);
    free(p);
    return 0;
}
