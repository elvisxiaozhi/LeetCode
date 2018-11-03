#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int> > result;

    for (unsigned int i = 0; i < nums.size() - 2; ++i) {
        for (unsigned int j = i + 1; j < nums.size() - 1; ++j) {
            for (unsigned int k = j + 1; k < nums.size(); ++k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> sum;
                    sum.push_back(nums[i]);
                    sum.push_back(nums[j]);
                    sum.push_back(nums[k]);

                    sort(sum.begin(), sum.end());
                    auto it = sum;

                    if (find(result.begin(), result.end(), it) != result.end()) {
                        continue;
                    }
                    else {
                        result.push_back(sum);
                    }
                }
            }
        }
    }

    return result;
}

vector<vector<int>> threeSum1(vector<int>& nums)
{
    sort(nums.begin(), nums.end());

    vector<vector<int> > result;

    for (unsigned int i = 0; i < nums.size() - 2; ++i) {
        for (unsigned int j = i + 1; j < nums.size() - 1; ++j) {
            int offset = -(nums[i] + nums[j]);
            if (find(nums.begin() + j + 1, nums.end(), offset) != nums.end()) {
                vector<int> sum;
                sum.push_back(nums[i]);
                sum.push_back(nums[j]);
                sum.push_back(offset);

                sort(sum.begin(), sum.end());
                auto it = sum;

                if (find(result.begin(), result.end(), it) != result.end()) {

                }
                else {
                    result.push_back(sum);
                }
            }
        }
    }

    return result;
}

vector<vector<int>> threeSum2(vector<int>& nums)
{
    vector<vector<int> > res;

    sort(nums.begin(), nums.end());

    for (unsigned int i = 0; i < nums.size(); i++) {
        int target = -nums[i];
        int front = i + 1;
        int back = nums.size() - 1;

        while (front < back) {
            int sum = nums[front] + nums[back];

            if (sum < target)
                front++;
            else if (sum > target)
                back--;
            else {
                vector<int> triplet(3, 0);
                triplet[0] = nums[i];
                triplet[1] = nums[front];
                triplet[2] = nums[back];
                res.push_back(triplet);

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && nums[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && nums[back] == triplet[2]) back--;
            }

        }

        // Processing duplicates of Number 1
        while (i + 1 < nums.size() && nums[i + 1] == nums[i])
            i++;
    }

    return res;
}

int main()
{
    vector<int> mVec1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int> > mVec2 = threeSum2(mVec1);

    for (unsigned int i = 0; i < mVec2.size(); ++i) {
        for (unsigned int j = 0; j < mVec2[i].size(); ++j) {
            cout << mVec2[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
