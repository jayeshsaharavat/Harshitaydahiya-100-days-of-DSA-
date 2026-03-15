/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root, int* arr, int* index)
{
    if(root == NULL)
        return;

    inorder(root->left, arr, index);
    arr[(*index)++] = root->val;
    inorder(root->right, arr, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* result = (int*)malloc(sizeof(int) * 1000);  // enough space
    int index = 0;

    inorder(root, result, &index);

    *returnSize = index;
    return result;
}
