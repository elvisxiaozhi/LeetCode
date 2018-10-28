#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int singleNumber(vector<int> &nums) //this one is faster
{
    sort(nums.begin(), nums.end());

    for (unsigned int i = 0; i < nums.size(); i += 2) {
        if (i == nums.size() - 1) {
            return nums[nums.size() - 1];
        }
        else if (nums[i] != nums[i + 1]) {
            if (nums[i + 2] == nums[i + 1]) {
                return nums[i];
            }
            else {
                return nums[i + 1];
            }
        }
    }

    return 0;
}

int singleNumber2(vector<int> &nums)
{
    vector<int> mVec;

    for (unsigned int i = 0; i < nums.size(); ++i) {
        auto it = find(mVec.begin(), mVec.end(), nums[i]);
        if (it != mVec.end()) {
            auto index = distance(mVec.begin(), it);
            mVec.erase(mVec.begin() + index);
        }
        else {
            mVec.push_back(nums[i]);
        }
    }

    return mVec[0];
}

int main()
{
    vector<int> mVec1 = {2, 2, 1};
    vector<int> mVec2 = {4, 1, 2, 1, 2};

    cout << singleNumber2(mVec1) << endl;
    cout << singleNumber2(mVec2) << endl;

    return 0;
}
