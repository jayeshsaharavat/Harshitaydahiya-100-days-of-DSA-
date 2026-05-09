/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced,
 * assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    int *rowA = *(int **)a;
    int *rowB = *(int **)b;

    return rowA[0] - rowB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {

    // Sort intervals according to start time
    qsort(intervals, intervalsSize, sizeof(int *), compare);

    // Allocate memory for result
    int **result = (int **)malloc(intervalsSize * sizeof(int *));
    *returnColumnSizes = (int *)malloc(intervalsSize * sizeof(int));

    int index = 0;

    // Insert first interval
    result[index] = (int *)malloc(2 * sizeof(int));
    result[index][0] = intervals[0][0];
    result[index][1] = intervals[0][1];
    (*returnColumnSizes)[index] = 2;

    // Traverse remaining intervals
    for (int i = 1; i < intervalsSize; i++) {

        // Overlapping intervals
        if (intervals[i][0] <= result[index][1]) {

            // Update ending point
            if (intervals[i][1] > result[index][1]) {
                result[index][1] = intervals[i][1];
            }

        } else {

            // Non-overlapping interval
            index++;

            result[index] = (int *)malloc(2 * sizeof(int));
            result[index][0] = intervals[i][0];
            result[index][1] = intervals[i][1];

            (*returnColumnSizes)[index] = 2;
        }
    }

    *returnSize = index + 1;
    return result;
}
