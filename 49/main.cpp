#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>

using namespace std;

vector<vector<string> > groupAnagrams(vector<string> &strs)
{
    vector<vector<string> > res;

    vector<string> temp(strs);
    for (unsigned int i = 0; i < temp.size(); ++i) {
        sort(temp[i].begin(), temp[i].end());
    }


    vector<int> mVec;
    for (unsigned int i = 0; i < temp.size(); ++i) {
        for (unsigned int j = i; j < temp.size(); ++j) {
            if (temp[i] == temp[j]) {
                if (find(mVec.begin(), mVec.end(), j) != mVec.end())
                    ;
                else {
                    mVec.push_back(j);
                }
            }
        }
        mVec.push_back(INT_MAX);
    }

    unsigned int n = 0;
    vector<string> strVec;
    while (n < mVec.size()) {
        if (mVec[n] != INT_MAX) {
            strVec.push_back(strs[mVec[n]]);
        }
        else {
            if (!strVec.empty()) {
                res.push_back(strVec);
                strVec.clear();
            }
        }
        ++n;
    }

    return res;
}

int main()
{
    vector<string> mVec= {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string> > res = groupAnagrams(mVec);

    for (unsigned int i = 0; i < res.size(); ++i) {
        for (unsigned int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
