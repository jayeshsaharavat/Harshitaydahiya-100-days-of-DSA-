#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    int min = INT_MAX, max = INT_MIN;

    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min) min = nums[i];
        if (nums[i] > max) max = nums[i];
    }

    if (min == max) return 0;

    
    int bucketSize = (max - min) / (numsSize - 1);
    if ((max - min) % (numsSize - 1) != 0)
        bucketSize++;

    int bucketCount = (max - min) / bucketSize + 1;

    int* bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int* bucketMax = (int*)malloc(bucketCount * sizeof(int));
    int* used = (int*)malloc(bucketCount * sizeof(int));

    
    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
        used[i] = 0;
    }

    
    for (int i = 0; i < numsSize; i++) {
        int index = (nums[i] - min) / bucketSize;

        if (!used[index]) {
            bucketMin[index] = nums[i];
            bucketMax[index] = nums[i];
            used[index] = 1;
        } else {
            if (nums[i] < bucketMin[index]) bucketMin[index] = nums[i];
            if (nums[i] > bucketMax[index]) bucketMax[index] = nums[i];
        }
    }

    
    int maxGap = 0;
    int prevMax = min;

    for (int i = 0; i < bucketCount; i++) {
        if (!used[i]) continue;

        int gap = bucketMin[i] - prevMax;
        if (gap > maxGap) maxGap = gap;

        prevMax = bucketMax[i];
    }

    free(bucketMin);
    free(bucketMax);
    free(used);

    return maxGap;
}
