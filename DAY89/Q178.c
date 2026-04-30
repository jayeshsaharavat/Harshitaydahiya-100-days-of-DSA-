int canShip(int* weights, int weightsSize, int days, int capacity) {
    int requiredDays = 1;
    int currentLoad = 0;

    for (int i = 0; i < weightsSize; i++) {
        
        if (currentLoad + weights[i] > capacity) {
            requiredDays++;
            currentLoad = 0;
        }
        currentLoad += weights[i];
    }

    return requiredDays <= days;
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int low = 0, high = 0;

    
    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > low)
            low = weights[i];  
        high += weights[i];   
    }

    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canShip(weights, weightsSize, days, mid)) {
            result = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;  
        }
    }

    return result;
}
