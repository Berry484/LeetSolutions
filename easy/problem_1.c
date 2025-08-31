/*
 * Problem    : 1
 * Difficulty : Easy
 * Language   : C
 * Time       : O(n^2)
 * Space      : O(1)
 */

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    for(int i = 0; i < numsSize; i++) {
        int aim = target - nums[i];
        for(int n = i +1; n < numsSize; n++) {
            if(nums[n] == aim) {
                int* arr = malloc(2 * sizeof(int));
                arr[0] = i;
                arr[1] = n;
                *returnSize = 2;
                return arr;
            }
        }
    }

    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    int returnSize = 0;

    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}

