/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root) {
    // Base case
    if (root == NULL)
        return 0;

    // Recursively find depth of left and right subtree
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    // Return max depth
    return 1 + (left > right ? left : right);
}
