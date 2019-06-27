#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    string res, shortestString;

    if (strs.empty()) {
        return res;
    }

    unsigned int i, length = INT_MAX, n = strs.size(), index;
    for (i = 0; i < n; ++i) {
        if (strs[i].length() < length) {
            shortestString = strs[i];
            length = strs[i].length();
            index = i;
        }
    }

    unsigned int j;
    for (i = 0; i < length; ++i) {
        for (j = 0; j < n; ++j) {
            if (shortestString[i] != strs[j][i]) {
                return res;
            }

            if (j == n - 1) {
                res.push_back(shortestString[i]);
            }
        }
    }

    return res;
}

int main()
{
    vector<string> vec1 = {"flower","flow","flight"};
    longestCommonPrefix(vec1);

    return 0;
}
