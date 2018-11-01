#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height)
{
    unsigned int max = 0;

    for (unsigned int i = 0; i < height.size() - 1; ++i) {
        unsigned int firstHeight = height[i];
        for (unsigned int j = i + 1; j < height.size(); ++j) {
            unsigned int lastHeight = height[j];

            if (firstHeight < lastHeight) {
                lastHeight = firstHeight;
            }

            unsigned int temp = (j - i) * lastHeight;

            if (temp > max) {
                max = temp;
            }
        }
    }

    return max;
}

int main()
{
    vector<int> mVec = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(mVec) << endl;

    return 0;
}
