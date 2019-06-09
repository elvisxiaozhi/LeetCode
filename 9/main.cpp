#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPalindrome(int x)
{
    if(x < 0) {
        return false;
    }

    int num = x;
    int digits = 0;
    while(num > 0) {
        num /= 10;
        ++digits;
    }

    vector<int> remainderVec;
    for(int i = 0; i < digits; ++i) {
        int remainder = 0;
        if(i == 0) {
            remainder = x % 10;
        }
        else {
            remainder = ((x / (int)pow(10, i)) % 10);
        }
        remainderVec.push_back(remainder);
    }

    int reversedNum = 0;
    for(int i = digits; i > 0; --i) {
        reversedNum += (remainderVec[digits - i] * (int)pow(10, i - 1));
    }

    if(reversedNum == x) {
        return true;
    }

    return false;
}

bool isPalindrome1(int x)
{
    if (x < 0) {
        return false;
    }

    string xStr = std::to_string(x);
    string xStrRev = std::to_string(x);
    std::reverse(xStrRev.begin(), xStrRev.end());

    if (xStr == xStrRev) {
        return true;
    }

    return false;
}

int main()
{
    cout << isPalindrome(121) << endl;
    return 0;
}
