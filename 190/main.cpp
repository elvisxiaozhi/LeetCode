#include <iostream>
#include <stack>
#include <string>
#include <stack>
#include <bitset>

using namespace std;

uint32_t reverseBits(uint32_t n)
{
    string s = std::bitset<32>(n).to_string();
    stack<char> mStack;
    for (int i = 0; i < s.size(); ++i) {
        mStack.push(s[i]);
    }

    s.clear();
    while (mStack.empty() == false) {
        s.push_back(mStack.top());
        mStack.pop();
    }

    int res = stoul(s, 0, 2);

    return res;
}

int main()
{
    reverseBits(43261596);

    return 0;
}
