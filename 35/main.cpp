#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int index = 0;

    auto it = find(nums.begin(), nums.end(), target);
    if(it != nums.end()) {
        index = it - nums.begin();
    }
    else {
        for(unsigned int i = 0; i < nums.size(); ++i) {
            if(target < nums[i]) {
                index = i;
                break;
            }
            else {
                ++index;
            }
        }
    }

    return index;
}

int main()
{
    vector<int> nums = {1,3,5,6};
    cout << searchInsert(nums, 0) << endl;;
    return 0;
}
