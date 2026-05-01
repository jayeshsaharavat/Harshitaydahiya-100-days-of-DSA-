#include <stdio.h>

int canSplit(int* nums, int numsSize, int k, int maxSum) {
    int count = 1;
    int currentSum = 0;

    for (int i = 0; i < numsSize; i++) {
        if (currentSum + nums[i] <= maxSum) {
            currentSum += nums[i];
        } else {
            count++;
            currentSum = nums[i];

            if (count > k)
                return 0;
        }
    }
    return 1;
}

int splitArray(int* nums, int numsSize, int k) {
    int low = nums[0], high = 0;

    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > low)
            low = nums[i];
        high += nums[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canSplit(nums, numsSize, k, mid)) {
            ans = mid;
            high = mid - 1;  
        } else {
            low = mid + 1;   
        }
    }

    return ans;
}
