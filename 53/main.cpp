#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int maxSubArray(vector<int>& nums)
{
    int sum = INT_MIN;

    for(unsigned int i = 0; i < nums.size(); ++i) {
        if(sum < nums[i]) {
            sum = nums[i];
        }
        int tempSum = nums[i];
        for(unsigned int j = i + 1; j < nums.size(); ++j) {
            tempSum += nums[j];
            if(tempSum > sum) {
                sum = tempSum;
            }
        }
    }

    return sum;
}

int main()
{
    vector<int> vec1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> vec2 = {-2, -5, 6, -2, -3, 1, 5, -6};
    vector<int> vec3 = {-1};
    cout << maxSubArray(vec1) << endl;
    cout << maxSubArray(vec2) << endl;
    cout << maxSubArray(vec3) << endl;

    return 0;
}
