// Height of Binary Tree

#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find height
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}


int main() {
    

    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Height of tree: %d\n", maxDepth(root));

    return 0;
}
