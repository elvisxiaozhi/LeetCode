#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int majorityElement(vector<int>& nums)
{
    map<int, int> mMap;

    for(unsigned int i = 0; i < nums.size(); ++i) {
        map<int, int>::iterator it = mMap.find(nums[i]);
        if(it != mMap.end()) {
            it->second += 1;
        }
        else {
            mMap.insert(make_pair(nums[i], 1));
        }
    }


    int element = 0;
    int repeatTimes = 0;

    for(auto const& x : mMap) {
        if(x.second > repeatTimes) {
            repeatTimes = x.second;
            element = x.first;
        }
    }

    return element;
}

int main()
{
    vector<int> mVector1 = {2,2,1,1,1,2,2};
    vector<int> mVector2 = {3, 2, 3};
    cout << majorityElement(mVector1) << endl;
    cout << majorityElement(mVector2) << endl;
    return 0;
}
