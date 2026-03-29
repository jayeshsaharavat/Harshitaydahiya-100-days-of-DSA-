struct TreeNode* prev = NULL;

void helper(struct TreeNode* root) {
    if (root == NULL)
        return;

    helper(root->right);
    helper(root->left);

    root->right = prev;
    root->left = NULL;

    prev = root;
}

void flatten(struct TreeNode* root) {
    prev = NULL;   // ✅ Reset for each test case
    helper(root);
}
