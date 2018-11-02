#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height)
{
    unsigned int maxArea = 0;

    for (unsigned int i = 0; i < height.size() - 1; ++i) {
        for (unsigned int j = i + 1; j < height.size(); ++j) {
            unsigned int minHeight = min(height[i], height[j]);
            maxArea = max(maxArea, (j - i) * minHeight);
        }
    }

    return maxArea;
}

int maxArea1(vector<int> &height)
{
    int maxarea = 0, l = 0, r = height.size() - 1;
    while (l < r) {
        maxarea = max(maxarea, min(height[l], height[r]) * (r - l));
        if (height[l] < height[r])
            l++;
        else
            r--;
    }

    return maxarea;
}

int main()
{
    vector<int> mVec = {1,8,6,2,5,4,8,3,7};
    cout << maxArea1(mVec) << endl;

    return 0;
}
