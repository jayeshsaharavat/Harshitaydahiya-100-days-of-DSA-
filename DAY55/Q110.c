/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Helper function for DFS
void dfs(struct TreeNode* root, int level, int* result, int* returnSize) {
    if (root == NULL) return;

    // If this is first node of this level
    if (level == *returnSize) {
        result[*returnSize] = root->val;
        (*returnSize)++;
    }

    // Visit right first
    dfs(root->right, level + 1, result, returnSize);
    dfs(root->left, level + 1, result, returnSize);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 1000); // enough for constraints
    *returnSize = 0;

    dfs(root, 0, result, returnSize);

    return result;
}
