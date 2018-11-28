#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode* root)
{
    vector<vector<int> > res;

    if (root == nullptr)
        return res;

    queue<TreeNode *> q;
    q.push(root);

    while (q.empty() == false) {
        int s = q.size();

        vector<int> mVec;
        while (s > 0) {
            TreeNode *node = q.front();
            q.pop();
            mVec.push_back(node->val);

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);

            --s;
        }
        res.push_back(mVec);
    }

    return res;
}

int main()
{
    TreeNode *node = new TreeNode(3);
    node->left = new TreeNode(9);
    node->right = new TreeNode(20);
    node->right->left = new TreeNode(15);
    node->right->right = new TreeNode(7);

    levelOrder(node);

    return 0;
}
