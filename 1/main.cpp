#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> vec;
    for(unsigned int i = 0; i < nums.size(); ++i) {
        for(unsigned int j = i + 1; j < nums.size(); ++j) {
            if(nums[i] + nums[j] == target) {
                vec.clear();
                vec.push_back(i);
                vec.push_back(j);
                cout << i << j << endl;
                break;
            }
        }
    }
    return vec;
}

int main()
{
    vector<int> vec = {2, 7, 11, 5};
    twoSum(vec, 9);
    return 0;
}
