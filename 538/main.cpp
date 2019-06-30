#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int returnSum(int num, TreeNode *root)
{
    int sum = 0;

    if (root == nullptr) {
        return sum;
    }

    if (root->val > num) {
        sum += root->val;
    }

    return (sum + returnSum(num, root->left) + returnSum(num, root->right));
}

void changeTree(TreeNode *root, TreeNode *copy)
{
    if (root == nullptr) {
        return;
    }

    root->val += returnSum(root->val, copy);

    changeTree(root->left, copy);
    changeTree(root->right, copy);
}

void printTree(TreeNode *root)
{
    if (root == nullptr) {
        return;
    }

    cout << root->val << endl;

    printTree(root->left);
    printTree(root->right);
}

TreeNode *copyTree(TreeNode *root)
{
     TreeNode *copy;

     if (root != nullptr) {
         copy = new TreeNode(root->val);
         copy->left = copyTree(root->left);
         copy->right = copyTree(root->right);
     }
     else {
         return nullptr;
     }

     return copy;
 }

TreeNode* convertBST(TreeNode* root)
{
    TreeNode *temp = copyTree(root);

    printTree(temp);

    changeTree(root, temp);

    return root;
}

int main()
{
    TreeNode *node = new TreeNode(5);
    node->left = new TreeNode(2);
    node->right = new TreeNode(13);

    convertBST(node);
    printTree(node);

    return 0;
}
