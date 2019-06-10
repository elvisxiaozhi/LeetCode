#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestConsecutive(vector<int>& nums)
{
    if (nums.empty() == true) {
        return 0;
    }
    if (nums.size() <= 1) {
        return 1;
    }

    sort(nums.begin(), nums.end());

    int res = 1, temp = 1, i, n = nums.size();
    for (i = 0; i < n - 1; ++i) {
        if (nums[i] == nums[i + 1]) {
            continue;
        }
        else if (nums[i] + 1 == nums[i + 1]) {
            ++temp;
        }
        else {
            temp = 1;
        }

        if (temp > res) {
            res = temp;
        }
    }

    return res;
}

int main()
{
    vector<int> mVec = {100, 4, 200, 1, 3, 2};
    vector<int> mVec1 = {100, 4, 200, 1, 3, 2, 101, 102, 103, 104, 105};

    cout << longestConsecutive(mVec) << endl;
    cout << longestConsecutive(mVec1) << endl;

    return 0;
}
