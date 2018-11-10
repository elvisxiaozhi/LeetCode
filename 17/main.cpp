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

vector<string> letterCombinations2(string digits) {
    vector<int> numbers;
    vector<string> preset = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    vector<string> finalResult;

    //把digits一个个拆分开，保存到numbers里面
    for (unsigned int i = 0; i < digits.size(); ++i) {
        numbers.push_back(digits[i] - '0');
    }

    unsigned int index = 1;

    //把numbers中的第一个按键，如按了2后，把a,b,c拆开保存到result里面
    if (numbers.size() > 0) {
        for (unsigned int i = 0; i < preset[numbers[0] - 2].size(); ++i) {
            string str = string() + preset[numbers[0] - 2][i];
            result.push_back(str);
        }
    }

    if (numbers.size() == 1) return result;

    while (index < numbers.size()) {
        finalResult.clear();

        //把numbers中，如刚才的a,b,c跟第二个按键，第三个按键拆开的结果结合到一起，保存到finalResult里面
        for (unsigned int i = 0; i < preset[numbers[index] - 2].size(); ++i) {
            for (unsigned int j = 0; j < result.size(); ++j) {
                string comb = string() + result[j] + preset[numbers[index] - 2][i];
                finalResult.push_back(comb);
            }
        }

        result.clear();
        result = finalResult;
        index += 1;
    }

    return finalResult;
}

int main()
{
    letterCombinations2("23");
    return 0;
}
