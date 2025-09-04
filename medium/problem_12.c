/**
 * Problem    : 12
 * Difficulty : Medium
 * Language   : C
 * Time       : O(n)
 * Space      : O(1)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Map {
    char* roman[13];
    int num[13];
};

char* intToRoman(int num) {
    struct Map map = {
        {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"},
        {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
    };
    
    int capacity = 20,
        pos = 0;
    char* roman_number = malloc(capacity);

    if(num == 0) {
        char* s = malloc(1);
        s[0] = '\0';
        return s;
    }

    for(int i = 0; i < 13; i++) {
        while(num >= map.num[i]) {
            int len = strlen(map.roman[i]);
            strcpy(&roman_number[pos], map.roman[i]);
            pos += len;
            num -= map.num[i];
        }
    }
    roman_number[pos] = '\0';
    return roman_number;
}

int main() {
    int value = 3749;
    char *s;

    s = intToRoman(value);

    printf("Number %i in roman is %s", value, s);
    return 0;
}


