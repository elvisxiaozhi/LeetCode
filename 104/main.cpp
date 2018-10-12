#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root)
{
    if(root == NULL) {
        return 0;
    }
    return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
}

int main()
{
    TreeNode *node = new TreeNode(3);
    node->left = new TreeNode(9);
    node->right = new TreeNode(20);
    node->right->left = new TreeNode(15);
    node->right->right = new TreeNode(7);

    cout << maxDepth(node) << endl;

    return 0;
}
