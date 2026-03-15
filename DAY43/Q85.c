//Construct a Binary Tree from the given level-order traversal.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

Node* buildTree(int arr[], int n)
{
    if(arr[0] == -1)
        return NULL;

    Node* root = createNode(arr[0]);

    Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while(i < n)
    {
        Node* curr = queue[front++];

        if(arr[i] != -1)
        {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if(i < n && arr[i] != -1)
        {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    Node* root = buildTree(arr,n);

    inorder(root);

    return 0;
}
