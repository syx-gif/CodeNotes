bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr) return false;            // 空树 / 走到空孩子：无路径
    // 到达叶子节点（左右都无孩子）
    if (root->left == nullptr && root->right == nullptr) {
        return root->val == sum;                  // 剩下的和正好等于叶子值
    }
    // 不是叶子：当前值减掉，继续去左右子树找
    return hasPathSum(root->left,  sum - root->val)
        || hasPathSum(root->right, sum - root->val);