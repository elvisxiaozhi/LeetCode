#include <iostream>
#include <vector>

using namespace std;

int extremeInsertionIndex(vector<int>& nums, int target, bool isTrue)
{
   int left = 0;
   int right = nums.size();

   while (left < right) {
       int mid = (left + right) / 2;
       if (nums[mid] > target || (isTrue && target == nums[mid])) {
           right = mid;
       }
       else {
           left = mid + 1;
       }
   }

   return left;
}

vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> targetRange = {-1, -1};

    unsigned int leftIdx = extremeInsertionIndex(nums, target, true);

    if (leftIdx == nums.size() || nums[leftIdx] != target) {
        return targetRange;
    }

    targetRange[0] = leftIdx;
    targetRange[1] = extremeInsertionIndex(nums, target, false) - 1;

    return targetRange;
}

vector<int> searchRange1(vector<int> &nums, int target)
{
    vector<int> targetRange = {-1, -1};

    // find the index of the leftmost appearance of `target`.
    for (unsigned int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            targetRange[0] = i;
            break;
        }
    }

    // if the last loop did not find any index, then there is no valid range
    // and we return [-1, -1].
    if (targetRange[0] == -1) {
        return targetRange;
    }

    // find the index of the rightmost appearance of `target` (by reverse
    // iteration). it is guaranteed to appear.
    for (int j = static_cast<int>(nums.size() - 1); j >= 0; j--) {
        if (nums[j] == target) {
            targetRange[1] = j;
            break;
        }
    }

    return targetRange;
}

int main()
{
    vector<int> mVec = {5,7,7,8,8,10};

    searchRange(mVec, 7);

    return 0;
}
