#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(string s)
{
    if(s.size() % 2 != 0) {
        return false;
    }

    vector<char> stringVec;

    for(unsigned int i = 0; i < s.size(); ++i) {
        if(s[i] == '[' || s[i] == '(' || s[i] == '{') {
            stringVec.push_back(s[i]);
        }
        else {
            if(stringVec.size() == 0) {
                return false;
            }
            else {
                if(s[i] == ']') {
                    if(stringVec.back() == '[') {
                        stringVec.pop_back();
                    }
                }
                else if(s[i] == ')') {
                    if(stringVec.back() == '(') {
                        stringVec.pop_back();
                    }
                }
                else if(s[i] == '}') {
                    if(stringVec.back() == '{') {
                        stringVec.pop_back();
                    }
                }
            }
        }
    }

    if(stringVec.size() > 0) {
        return false;
    }

    return true;
}

int main()
{
    cout << isValid("()[") << endl;
    return 0;
}
