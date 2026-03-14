#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *data;
    int size;
    int capacity;
    int isMinHeap; // 1 for Min-Heap, 0 for Max-Heap
} Heap;

// Helper to create a heap
Heap* createHeap(int capacity, int isMinHeap) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->data = (int*)malloc(sizeof(int) * (capacity + 1));
    h->size = 0;
    h->capacity = capacity;
    h->isMinHeap = isMinHeap;
    return h;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap* h, int val) {
    h->data[++(h->size)] = val;
    int curr = h->size;
    while (curr > 1) {
        int parent = curr / 2;
        if ((h->isMinHeap && h->data[curr] < h->data[parent]) || 
            (!h->isMinHeap && h->data[curr] > h->data[parent])) {
            swap(&h->data[curr], &h->data[parent]);
            curr = parent;
        } else break;
    }
}

int pop(Heap* h) {
    int top = h->data[1];
    h->data[1] = h->data[h->size--];
    int curr = 1;
    while (curr * 2 <= h->size) {
        int child = curr * 2;
        if (child + 1 <= h->size) {
            if ((h->isMinHeap && h->data[child+1] < h->data[child]) || 
                (!h->isMinHeap && h->data[child+1] > h->data[child])) {
                child++;
            }
        }
        if ((h->isMinHeap && h->data[child] < h->data[curr]) || 
            (!h->isMinHeap && h->data[child] > h->data[curr])) {
            swap(&h->data[curr], &h->data[child]);
            curr = child;
        } else break;
    }
    return top;
}

// LeetCode Class Structure
typedef struct {
    Heap* smallMaxHeap; // Stores small half
    Heap* largeMinHeap; // Stores large half
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* mf = (MedianFinder*)malloc(sizeof(MedianFinder));
    mf->smallMaxHeap = createHeap(50001, 0);
    mf->largeMinHeap = createHeap(50001, 1);
    return mf;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    // 1. Add to Max-Heap
    push(obj->smallMaxHeap, num);
    
    // 2. Balancing: move largest of small-half to large-half
    push(obj->largeMinHeap, pop(obj->smallMaxHeap));
    
    // 3. Keep size property: smallMaxHeap size >= largeMinHeap size
    if (obj->smallMaxHeap->size < obj->largeMinHeap->size) {
        push(obj->smallMaxHeap, pop(obj->largeMinHeap));
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->smallMaxHeap->size > obj->largeMinHeap->size) {
        return (double)obj->smallMaxHeap->data[1];
    }
    return (obj->smallMaxHeap->data[1] + obj->largeMinHeap->data[1]) * 0.5;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->smallMaxHeap->data);
    free(obj->smallMaxHeap);
    free(obj->largeMinHeap->data);
    free(obj->largeMinHeap);
    free(obj);
}
