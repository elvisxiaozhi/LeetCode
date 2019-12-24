#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    if (nums.empty())
        return 0;

    stack<int> stack;
    stack.push(nums[nums.size() - 1]);
    for (int i = nums.size() - 2; i >= 0; --i) {
        if (stack.top() != nums[i]) {
            stack.push(nums[i]);
        }
    }

    nums.clear();
    while (stack.empty() == false) {
        nums.push_back(stack.top());
        stack.pop();
    }

    return nums.size();
}

int main()
{
    vector<int> mVec = {0,0,1,1,1,2,2,3,3,4};
    removeDuplicates(mVec);

    return 0;
}
