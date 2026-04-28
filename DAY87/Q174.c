int max(int a, int b) {
    return (a > b) ? a : b;
}


long long calculateHours(int* piles, int pilesSize, int k) {
    long long hours = 0;
    for(int i = 0; i < pilesSize; i++) {
        
        hours += (piles[i] + k - 1) / k;
    }
    return hours;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1;
    int right = 0;

    
    for(int i = 0; i < pilesSize; i++) {
        right = max(right, piles[i]);
    }

    int result = right;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        long long hours = calculateHours(piles, pilesSize, mid);

        if(hours <= h) {
            result = mid;     
            right = mid - 1;  
        } else {
            left = mid + 1;   
        }
    }

    return result;
}
