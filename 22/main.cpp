#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<string> &ans, string temp, int open, int close, int max)
{
    if (close == max) {
        ans.push_back(temp);
        return;
    }
    else {
        if (close < open) {
            backtrack(ans, temp + ')', open, close + 1, max);
        }
        if (open < max) {
            backtrack(ans, temp + '(', open + 1, close, max);
        }
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    if (n > 0) {
        backtrack(ans, "", 0, 0, n);
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
}

int main()
{
    generateParenthesis(3);
    return 0;
}
