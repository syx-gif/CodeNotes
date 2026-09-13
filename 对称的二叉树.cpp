bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr && t2 == nullptr) return true;   // 都空
    if (t1 == nullptr || t2 == nullptr) return false;  // 一个空
    if (t1->val != t2->val) return false;              // 值不等
    // 关键：外侧对外侧，内侧对内侧
    return isMirror(t1->left,  t2->right)
        && isMirror(t1->right, t2->left);
}

// 牛客 BM31 的函数名是 isSymmetrical
bool isSymmetrical(TreeNode* pRoot) {
    if (pRoot == nullptr) return true;          // 空树约定为对称
    return isMirror(pRoot->left, pRoot->right);
}
