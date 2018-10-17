#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
{
    if(t1 == NULL) {
        return t2;
    }
    if(t2 == NULL) {
        return t1;
    }

    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);

    return t1;
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
    TreeNode *node1 = new TreeNode(1);
    node1->left = new TreeNode(3);
    node1->right = new TreeNode(2);
    node1->left->left = new TreeNode(5);

    TreeNode *node2 = new TreeNode(2);
    node2->left = new TreeNode(1);
    node2->right = new TreeNode(3);
    node2->left->right = new TreeNode(4);
    node2->right->right = new TreeNode(7);

    TreeNode *node3 = mergeTrees(node1, node2);

    printTreeNode(node2);
    cout << endl;
    printTreeNode(node3);

    return 0;
}
