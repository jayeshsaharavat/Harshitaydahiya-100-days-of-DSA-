#include <stdio.h>

int integerSquareRoot(int n) {
    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid * mid == n) {
            return mid;  // exact square root
        }
        else if (mid * mid < n) {
            ans = mid;   // store possible answer
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", integerSquareRoot(n));

    return 0;
}
