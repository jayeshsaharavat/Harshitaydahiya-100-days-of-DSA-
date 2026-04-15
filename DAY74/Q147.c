#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][LEN];
    char names[MAX][LEN];
    int count[MAX] = {0};
    int unique = 0;

    // Read votes
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);

        int found = -1;

        // Check if name already exists
        for (int j = 0; j < unique; j++) {
            if (strcmp(names[j], votes[i]) == 0) {
                found = j;
                break;
            }
        }

        // If found, increase count
        if (found != -1) {
            count[found]++;
        } else {
            // New candidate
            strcpy(names[unique], votes[i]);
            count[unique] = 1;
            unique++;
        }
    }

    // Find maximum votes
    int max_votes = 0;
    for (int i = 0; i < unique; i++) {
        if (count[i] > max_votes) {
            max_votes = count[i];
        }
    }

    // Find lexicographically smallest among max वोट candidates
    char winner[LEN];
    int first = 1;

    for (int i = 0; i < unique; i++) {
        if (count[i] == max_votes) {
            if (first || strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
                first = 0;
            }
        }
    }

    // Output
    printf("%s %d\n", winner, max_votes);

    return 0;
}
