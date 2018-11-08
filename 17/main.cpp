#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<char, vector<char> > mMap;
vector<char> mVec2 = {'a', 'b', 'c'};
vector<char> mVec3 = {'d', 'e', 'f'};
vector<char> mVec4 = {'g', 'h', 'i'};
vector<char> mVec5 = {'j', 'k', 'l'};
vector<char> mVec6 = {'m', 'n', 'o'};
vector<char> mVec7 = {'p', 'q', 'r', 's'};
vector<char> mVec8 = {'t', 'u', 'v'};
vector<char> mVec9 = {'w', 'x', 'y', 'z'};

vector<string> letterCombinations(string digits) {
    mMap['2'] = mVec2;
    mMap['3'] = mVec3;
    mMap['4'] = mVec4;
    mMap['5'] = mVec5;
    mMap['6'] = mVec6;
    mMap['7'] = mVec7;
    mMap['8'] = mVec8;
    mMap['9'] = mVec9;

    vector<string> res;

    for (unsigned int i = 0; i < digits.size(); ++i) {
        for (unsigned int j = 0; j < mMap.at(digits[i]).size(); ++j) {
            cout << mMap.at(digits[i])[j] << "\t";
        }
        cout << endl;
    }

    for (unsigned int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }

    return res;
}

vector<string> letterCombinations1(string digits)
{
    vector<string> res;

    if (digits.empty()) {
        return res;
    }

    vector<string> mVec = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    res.push_back("");

    while (res.front().size() != digits.length()) {
        string removed = res.front();
        res.erase(res.begin() + 0);
        string mStr = mVec[digits[removed.size()] - '0'];
        for (unsigned int i = 0; i < mStr.size(); ++i) {
            res.push_back(removed + mStr[i]);
        }
    }

    return res;
}

int main()
{
    letterCombinations1("23");
    return 0;
}
