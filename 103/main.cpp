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

vector<vector<int> > zigzagLevelOrder(TreeNode* root)
{
    if (!root) return {};

    queue<TreeNode *> q;
    q.push(root);
    vector<vector<int>> out;

    while (!q.empty()) {

        int sz = q.size();
        vector<int> curr(sz);

        for (int i = 0; i < sz; ++i) {
            TreeNode *tmp = q.front();
            q.pop();
            curr[i] = tmp->val;

            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
        out.push_back(curr);
    }
    return out;

}

int main()
{
    TreeNode *node = new TreeNode(3);
    node->left = new TreeNode(9);
    node->right = new TreeNode(20);
    node->right->left = new TreeNode(15);
    node->left->right = new TreeNode(7);

    return 0;
}
