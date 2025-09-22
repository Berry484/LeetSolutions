/**
 * Problem    : 3005
 * Difficulty : Easy
 * Language   : C
 * Time       : O(n)
 * Space      : O(1)
 */

#include <stdio.h>
#include <stdlib.h>

int maxFrequencyElements(int* nums, int numsSize);

int main() {
    int nums[] = {1, 2, 2, 3, 1, 4};
    printf("Highest freq = %i", maxFrequencyElements(nums, 6));

    printf("\n\n");
    return 0;
}

/**
 * Returns the count of highest frequency.
 *
 * @param   nums        -Array of ints we want to check.
 * @param   numsSize    -Size of nums
 *
 * @return the count of highest frequency.
 */
int maxFrequencyElements(int* nums, int numsSize) {
    int max = 0,
        highest_freq = 0;

    int* frequencies = calloc(200, sizeof(int));


    for (int i = 0; i < numsSize; i++) {
        frequencies[nums[i]-1]++;
        if (frequencies[nums[i]-1] > highest_freq)
            highest_freq = frequencies[nums[i]-1];
    }

    for (int i = 0; i < 100; i++) {
        if (frequencies[i] == highest_freq)
            max += frequencies[i];
    }

    free(frequencies);
    return max;
}
