#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinStack {
    vector<int> nums;
    int minNum;

public:
    MinStack() {

    }

    void push(int x) {
        if (nums.empty()) {
            minNum = x;
        }
        else {
            minNum = min(minNum, x);
        }

        nums.push_back(x);
    }

    int top() {
        if (!nums.empty()) {
            return nums.back();
        }
    }

    void pop() {
        if (top() == minNum) {
            if (nums.size() > 1) {
                minNum = nums[0];
                for (unsigned int i = 0; i < nums.size() - 1; ++i) {
                    minNum = min(minNum, nums[i]);
                }
            }
        }
        nums.pop_back();
    }

    int getMin() {
        return minNum;
    }
};

int main()
{   
    return 0;
}
