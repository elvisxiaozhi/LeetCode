#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> res;

    stack<TreeNode *> s;
    TreeNode *curr = root;

    while (curr != nullptr || !s.empty()) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }

    return res;
}

int main()
{
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->right->left = new TreeNode(4);
    node->right->right = new TreeNode(5);

    vector<int> mVec = inorderTraversal(node);

    for (unsigned int i = 0; i < mVec.size(); ++i) {
        cout << mVec[i] << endl;
    }

    return 0;
}
