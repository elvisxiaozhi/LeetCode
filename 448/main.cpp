#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    vector<int> mVec;

    //fix reference binding to null pointer of type 'int'
//    if (nums.empty()) {
//        return mVec;
//    }

//    int max = *max_element(nums.begin(), nums.end());

//    int size = static_cast<int>(nums.size());
//    if (max < size) {
//        max = size;
//    }

//    for (int i = 1; i <= max; ++i) {
//        if (std::find(nums.begin(), nums.end(), i) != nums.end()) {
//            continue;
//        }
//        else {
//            mVec.push_back(i);
//        }
//    }

    for (unsigned int i = 0; i < nums.size(); ++i) {
        int val = abs(nums[i]) - 1;
        if (nums[val] > 0) {
            nums[val] = -nums[val];
        }
    }

    for (unsigned int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) {
            mVec.push_back(i + 1);
        }
    }

    return mVec;
}

int main()
{
    vector<int> mVec = {4,3,2,7,8,2,3,1}; //4,3,2,7,8,2,3,1
//    vector<int> mVec1 = {2,2};
    vector<int> mVec2 = findDisappearedNumbers(mVec);

    for (unsigned int i = 0; i < mVec2.size(); ++i) {
        cout << mVec2[i] << endl;
    }

    return 0;
}
