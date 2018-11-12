#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target)
{
    int res = -1;

    for (unsigned int i = 0; i < nums.size(); ++i) {
        if (target == nums[i]) {
            return i;
        }
    }

    return res;
}

int main()
{
    vector<int> mVec = {4,5,6,7,0,1,2};
    cout << search(mVec, 0) << endl;

    return 0;
}
