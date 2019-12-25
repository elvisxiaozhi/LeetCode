#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    stack<int> firstStack;
    for (int i = 0; i < digits.size(); ++i) {
        firstStack.push(digits[i]);
    }

    firstStack.top() += 1;

    stack<int> secondStack;
    while (firstStack.empty() == false) {
        if (firstStack.top() < 10) {
            secondStack.push(firstStack.top());
            firstStack.pop();
        }
        else {
            secondStack.push(firstStack.top() - 10);
            firstStack.pop();
            if (firstStack.empty() == false) {
                firstStack.top() += 1;
            }
            else {
                secondStack.push(1);
            }
        }
    }

    digits.clear();
    while (secondStack.empty() == false) {
        digits.push_back(secondStack.top());
        secondStack.pop();

    }

    return digits;
}

int main()
{
    vector<int> mVec = {9, 9};
    plusOne(mVec);

    return 0;
}
