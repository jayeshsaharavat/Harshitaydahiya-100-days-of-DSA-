void rotate(int* nums, int numsSize, int k) {
    if (numsSize <= 1) return;
    k %= numsSize;
  
    for (int i = 0, j = numsSize - 1; i < j; i++, j--) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    for (int i = 0, j = k - 1; i < j; i++, j--) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
  
    for (int i = k, j = numsSize - 1; i < j; i++, j--) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
