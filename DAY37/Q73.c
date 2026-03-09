//Implement a Priority Queue using an array. An element with smaller value has higher priority.

#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element
void insert(int x)
{
    if(size == MAX)
        return;

    pq[size++] = x;
}

// Find index of smallest element
int findMinIndex()
{
    if(size == 0)
        return -1;

    int minIndex = 0;

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[minIndex])
            minIndex = i;
    }

    return minIndex;
}

// Delete highest priority element
void deletePQ()
{
    int index = findMinIndex();

    if(index == -1)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[index]);

    for(int i = index; i < size-1; i++)
        pq[i] = pq[i+1];

    size--;
}

// Peek highest priority element
void peek()
{
    int index = findMinIndex();

    if(index == -1)
        printf("-1\n");
    else
        printf("%d\n", pq[index]);
}

int main()
{
    int n, x;
    char op[10];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "delete") == 0)
        {
            deletePQ();
        }
        else if(strcmp(op, "peek") == 0)
        {
            peek();
        }
    }

    return 0;
}
