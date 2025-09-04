/**
 * Problem    : 11
 * Difficulty : Medium
 * Language   : C
 * Time       : O(n)
 * Space      : O(1)
 */

#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize) {
    int water = 0,
        left = 0,
        right = heightSize - 1,

        shortest = 0,
        max_water = 0;
    while(left < right) {
        shortest = (height[left] < height[right]) ? height[left] : height[right];
        water = shortest * (right - left);

        if(height[left] < height[right])
            left++;
        else
            right--;

        if(water > max_water)
            max_water = water; 
    }
    
    return max_water;
}

int main() {
    int heightSize = 9,
        water = 0;

    int* height = malloc(heightSize * sizeof(int));
    int temp[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    for(int i = 0; i < heightSize; i++)
        height[i] = temp[i];

    water = maxArea(height, heightSize);
    free(height);

    printf("Max water = %i\n\n", water);

    return 0;
}
