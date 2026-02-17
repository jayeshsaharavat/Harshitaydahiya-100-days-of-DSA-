#include <stdio.h>
#include <limits.h>

int maxSubArray(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    int max_ending_here = nums[0];
    int max_so_far = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        max_ending_here = (nums[i] > max_ending_here + nums[i]) ? nums[i] : max_ending_here + nums[i];
        max_so_far = (max_so_far > max_ending_here) ? max_so_far : max_ending_here;
    }
    
    return max_so_far;
}
