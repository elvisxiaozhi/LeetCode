#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<string> letArr = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void CombineNext(string sNow, unsigned int nextIndex, string input, vector<string> &res) //using recursive
{
    string s, sl;

    if (nextIndex > input.size()) {
        return;
    }

    sl = letArr[(input[nextIndex] - '0') - 2];

    for (unsigned int i = 0; i < sl.size(); ++i) {
        s = sNow + sl[i];
        if (s.size() == input.size()) {
            cout << s << endl;
            res.push_back(s);
        }
        else {
            CombineNext(s, nextIndex + 1, input, res);
        }
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> res;

    string firstInputStr = letArr[(digits[0] - '0') - 2];

    for (unsigned int j = 0; j < firstInputStr.size(); ++j) {
        string mStr;
        mStr.push_back(firstInputStr[j]);
        if (digits.size() == 1) {
            res.push_back(mStr);
        }
        else {
            CombineNext(mStr, 1, digits, res);
        }
    }

    return res;
}

vector<string> letterCombinations1(string digits) //using BFS
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
    letterCombinations("23");
    return 0;
}
