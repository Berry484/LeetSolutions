*/*
 * Problem    : 16
 * Difficulty : Medium
 * Language   : C
 * Time       : O(n^2)
 * Space      : O(1)
 */

#include <stdio.h>
#include <stdlib.h>

int compareInt(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compareInt);
    int closest = nums[0] + nums[1] + nums[2];

    for(int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum < target)
                left++;
            else
                right--;

            if(abs(target - sum) < abs(target - closest))
                closest = sum;
        }
    }

    return closest;
}

int main() {
    int* nums = malloc(4 * sizeof(int));
    int numsSize = 4,
        target = 1;
    int temp[4] = {-1, 2, 1, -4};

    for(int i = 0; i < numsSize; i++)
        nums[i] = temp[i];

    int output = threeSumClosest(nums, numsSize, target);
    printf("Output = %i\n\n", output);

    return 0;
}
