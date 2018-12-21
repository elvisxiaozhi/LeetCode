#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int res = 0;

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    res = std::max(res, left + right);

    return std::max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    maxDepth(root);
    return res;
}

int main()
{
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->left->left = new TreeNode(4);
    node->left->right = new TreeNode(5);

    cout << diameterOfBinaryTree(node) << endl;

    return 0;
}
