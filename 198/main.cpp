#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums)
{
    if (nums.size() == 0) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }

    int *dp = new int[nums.size()];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (unsigned int i = 2; i < nums.size(); ++i) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }

    return dp[nums.size() - 1];
}

int main()
{
    vector<int> mVector1 = {1, 2, 3, 1};
    vector<int> mVector2 = {2, 7, 9, 3, 1};
    vector<int> mVector3 = {2, 1, 1, 2};

    cout << rob(mVector1) << endl;
    cout << rob(mVector2) << endl;
    cout << rob(mVector3) << endl;

    return 0;
}
