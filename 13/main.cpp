#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<char> charVec = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
vector<int> numVec = {1, 5, 10, 50, 100, 500, 1000};

int romanToInt(string s)
{
    int num = 0;
    for(unsigned int i = 0; i < s.size(); ++i) {
        int firstPos = std::find(charVec.begin(), charVec.end(), s[i]) - charVec.begin();
        int secPos = 0;
        if(i != s.size() - 1) {
            secPos = std::find(charVec.begin(), charVec.end(), s[i + 1]) - charVec.begin();
        }
        if(secPos > firstPos) {
            num += numVec[secPos] - numVec[firstPos];
            ++i;
        }
        else {
            num += numVec[firstPos];
        }
    }

    return num;
}

int main()
{
    romanToInt("MCMXCIV");
    return 0;
}
