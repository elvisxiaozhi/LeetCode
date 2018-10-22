#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void moveZeroes(vector<int>& nums)
{
    unsigned int vectorSize = nums.size();
    unsigned int noneZeroNums = 0;
    for (unsigned int i = 0; i < vectorSize; ++i) {
        if (nums[i] != 0) {
            ++noneZeroNums;
            nums.push_back(nums[i]);
        }
    }

    for (unsigned int i = 0; i < vectorSize; ++i) {
        nums.erase(nums.begin());
    }

    for (unsigned int i = 0; i < vectorSize - noneZeroNums; ++i) {
        nums.push_back(0);
    }
}

void moveZeroes1(vector<int>& nums)
{
    if (nums.size() == 0 || nums.size() == 1){
        return;
    }

    int count = 0;

    for(unsigned int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[count++] = nums[i];
        }

    }

    for(unsigned int i = count; i < nums.size(); i++) {
        nums[i] = 0;
    }
}

int main()
{
    vector<int> mVector = {4,2,4,0,0,3,0,5,1,0};

    moveZeroes1(mVector);

    for (unsigned int i = 0; i < mVector.size(); ++i) {
        cout << mVector[i] << endl;
    }

    return 0;
}
