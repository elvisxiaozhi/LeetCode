#include <iostream>

using namespace std;

int mySqrt_1(int x)
{
    if (x < 2) {
        return x;
    }

    for (unsigned int i = 0; i <= x; ++i) {
        if (i * i > x) {
            return i - 1;
        }
    }

    return x;
}

int mySqrt(int x) //using binary search
{
    if (x < 2)
        return x;

    int left = 1, right = x / 2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid <= x / mid && (mid + 1) > x / (mid + 1))
            return mid;
        else if (mid + 1 < x / mid + 1)
            left = mid + 1;
        else if (mid + 1 == x / mid + 1)
            return mid + 1;
        else
            right = mid - 1;
    }

    return 1;
}

int main()
{
    cout << mySqrt(2) << endl;
    cout << mySqrt(4) << endl;
    cout << mySqrt(8) << endl;
    cout << mySqrt(9) << endl;
    cout << mySqrt(2147395600) << endl;
    cout << mySqrt_1(2147395600) << endl;

    return 0;
}
