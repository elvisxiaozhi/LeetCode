#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

string longestCommonPrefix_1(vector<string>& strs) //using sort method
{
    string res;
    if (strs.empty()) {
        return res;
    }

    sort(strs.begin(), strs.end());

    string str1 = strs[0];
    string str2 = strs[strs.size() - 1];
    unsigned int i, n = max(str1.size(), str2.size());
    for (i = 0; i < n; ++i) {
        if (str1[i] == str2[i]) {
            res.push_back(str1[i]);
        }
        else {
            break;
        }
    }

    return res;
}

int main()
{
    vector<string> vec1 = {"flower","flow","flight"};
    cout << longestCommonPrefix(vec1) << endl;
    cout << longestCommonPrefix_1(vec1) << endl;

    return 0;
}
