#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int nums[100005];  // Handles up to 10^5 elements safely
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    int max_num = nums[0];
    int min_num = nums[0];
    
    for(int i = 1; i < n; i++) {
        if(nums[i] > max_num) max_num = nums[i];
        if(nums[i] < min_num) min_num = nums[i];
    }
    
    printf("Max: %d\nMin: %d\n", max_num, min_num);
    return 0;
}
