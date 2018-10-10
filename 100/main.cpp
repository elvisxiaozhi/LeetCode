#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q)
{
    if(p == NULL && q == NULL) {
        return true;
    }
    else if(p == NULL && q != NULL) {
        return false;
    }
    else if(p != NULL && q == NULL) {
        return false;
    }

    if(p->val == q->val) {
        return (true && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }

    return false;
}

int main()
{

    TreeNode *head1 = new TreeNode(1);
    head1->left = new TreeNode(2);
    head1->right = new TreeNode(2);

    TreeNode *head2 = new TreeNode(1);
    head2->left = new TreeNode(2);
    head2->right = new TreeNode(2);

    cout << isSameTree(head1, head2) << endl;

    return 0;
}
