#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSame(TreeNode *a, TreeNode *b)
{
    if (a == nullptr || b == nullptr)
        return b == a;

    return (a->val == b->val && isSame(a->left, b->left) && isSame(a->right, b->right));
}

bool isSubtree(TreeNode *s, TreeNode *t)
{
    if (s == nullptr)
        return t == nullptr;

    return isSame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}

int main()
{
    TreeNode *node = new TreeNode(3);
    node->left = new TreeNode(4);
    node->right = new TreeNode(5);
    node->left->left = new TreeNode(1);
    node->left->right = new TreeNode(2);
//    node->left->right->left = new TreeNode(5);

    TreeNode *sub = new TreeNode(4);
    sub->left = new TreeNode(1);
    sub->right = new TreeNode(2);

    cout << isSubtree(node, sub) << endl;

    return 0;
}
