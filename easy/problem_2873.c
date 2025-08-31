/*
 * Problem    : 2873
 * Difficulty : Easy
 * Language   : C
 * Time       : O(n)
 * Space      : O(1)
 */

#include <stdio.h>
#include <stdlib.h>

long long maximumTripletValue(int* nums, int numsSize) {
    long long max_sum = 0;
    long long sum = 0;
    
    int max_i = 0;
    long long i_j_sum = 0;
    long long temp_sum = 0;

    for(int i = 2; i < numsSize; i++) {
       if(nums[i - 2] > max_i)
           max_i = nums[i - 2];
       temp_sum = (long long)max_i - nums[i - 1];
       if(temp_sum > i_j_sum)
           i_j_sum = temp_sum;

       sum = (long long)(i_j_sum * nums[i]);
       if(sum > max_sum)
           max_sum = sum;
    }
    return max_sum;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    long long result = maximumTripletValue(nums, numsSize);
    printf("Maximum triplet value = %lld\n", result);

    return 0;
}
