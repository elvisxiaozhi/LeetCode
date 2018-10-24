#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



TreeNode* invertTree(TreeNode* root)
{
    if (root == nullptr)
        return root;

    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

void printTreeNode(TreeNode *node)
{
    if (!node) {
        return;
    }

    if (!node->left && !node->right) {
        cout << node->val << endl;
        return;
    }
    else {
        cout << node->val << endl;
    }

    if (node->left) {
        printTreeNode(node->left);
    }

    if (node->right) {
        printTreeNode(node->right);
    }
}

int main()
{
    TreeNode *node = new TreeNode(4);
    node->left = new TreeNode(2);
    node->right = new TreeNode(7);
    node->left->left = new TreeNode(1);
    node->left->right = new TreeNode(3);
    node->right->left = new TreeNode(6);
    node->right->right = new TreeNode(9);

    invertTree(node);
    printTreeNode(node);

    return 0;
}
