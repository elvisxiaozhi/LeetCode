#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int findUnsortedSubarray(vector<int>& nums)
{
    vector<int> mVec(nums);
    sort(mVec.begin(), mVec.end());
    int start = nums.size(), end = 0;

    for (int i = 0; i < static_cast<int>(mVec.size()); ++i) {
        if (mVec[i] != nums[i]) {
            start = min(start, i);
            end = max(end, i);
        }
    }

    return (end - start >= 0 ? end - start + 1 : 0);
}

int main()
{
    vector<int> mVec = {2, 6, 4, 8, 10, 9, 15};
    cout << findUnsortedSubarray(mVec) << endl;

    return 0;
}
