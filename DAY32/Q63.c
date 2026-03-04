//Implement push and pop operations on a stack and verify stack operations.


#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
int main()
{
    int n, m, i;

    
    scanf("%d", &n);

    
    for(i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);

        if(top == MAX - 1)
        {
            printf("Stack Overflow\n");
            return 0;
        }
        top++;
        stack[top] = value;
    }

    // Read number of pops
    scanf("%d", &m);

    // Perform m pops
    for(i = 0; i < m; i++)
    {
        if(top == -1)
        {
            printf("Stack Underflow\n");
            return 0;
        }

        top--;
    }

    
    if(top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        for(i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
    return 0;
}
