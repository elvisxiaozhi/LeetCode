#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int reverse(int x)
{
    bool isNegative = false;
    if (x < 0) {
        isNegative = true;
    }

    string mStr = to_string(x);
    std::reverse(mStr.begin(), mStr.end());

    int ans;
    if (stoll(mStr) > 2147483647 || stoll(mStr) < -2147483647)  {
        return 0;
    }
    else {
        ans = static_cast<int>(stol(mStr));
    }

    if (isNegative) {
        ans = -ans;
    }

    return ans;
}

int main()
{
    cout << reverse(1534236469) << endl;
    cout << reverse(124) << endl;
    return 0;
}
