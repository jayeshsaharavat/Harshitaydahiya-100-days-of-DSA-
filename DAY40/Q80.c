int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    
    int* answer = (int*)malloc(sizeof(int) * temperaturesSize);
    int stack[temperaturesSize];
    int top = -1;

    for(int i = 0; i < temperaturesSize; i++)
        answer[i] = 0;

    for(int i = 0; i < temperaturesSize; i++)
    {
        while(top != -1 && temperatures[i] > temperatures[stack[top]])
        {
            int index = stack[top--];
            answer[index] = i - index;
        }

        stack[++top] = i;
    }

    *returnSize = temperaturesSize;
    return answer;
}
