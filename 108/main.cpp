#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* bst(vector<int>& nums,int low,int high)
{
    if (low > high)
        return NULL;

    int mid = (low + high) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = bst(nums, low, mid - 1);
    root->right = bst(nums, mid + 1, high);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    return bst(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> mVec = {-10,-3,0,5,9};
    sortedArrayToBST(mVec);

    return 0;
}
