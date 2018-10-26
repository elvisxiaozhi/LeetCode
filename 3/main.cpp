#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.empty()) {
        return 0;
    }

    vector<char> mVec1;
    unsigned int longestLength = 0;

    for (unsigned int i = 0; i < s.size(); ++i) {
        mVec1.clear();
        for (unsigned int j = i; j < s.size(); ++j) {
            if (find(mVec1.begin(), mVec1.end(), s[j]) != mVec1.end()) {
                if (longestLength < mVec1.size()) {
                    longestLength = mVec1.size();
                }
                break;
            }
            else {
                mVec1.push_back(s[j]);
            }

            if (j == s.size() - 1) {
                if (longestLength < mVec1.size()) {
                    longestLength = mVec1.size();
                }
            }
        }
    }

    return longestLength;
}

int main()
{
    string str1 = "abcabcbb";
    string str2 = "bbbbb";
    string str3 = "pwwkew";
    string str4 = "au";
    string str5 = "aab";

    cout << lengthOfLongestSubstring(str1) << endl;
    cout << lengthOfLongestSubstring(str2) << endl;
    cout << lengthOfLongestSubstring(str3) << endl;
    cout << lengthOfLongestSubstring(str4) << endl;
    cout << lengthOfLongestSubstring(str5) << endl;

    return 0;
}
