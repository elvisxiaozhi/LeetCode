#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool compare(TreeNode *node1, TreeNode *node2)
{
    if(node1 == NULL && node2 == NULL) {
        return true;
    }
    if(node1 == NULL || node2 == NULL) {
        return false;
    }

    return ((node1->val == node2->val) && compare(node1->left, node2->right) && compare(node1->right, node2->left));
}

bool isSymmetric(TreeNode* root)
{
    return compare(root, root);
}

int main()
{
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(2);
    node->left->left = new TreeNode(3);
    node->left->right = new TreeNode(4);
    node->right->left = new TreeNode(4);
    node->right->right = new TreeNode(3);

    cout << isSymmetric(node) << endl;

    return 0;
}
