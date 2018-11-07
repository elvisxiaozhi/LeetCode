#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

string decToBinary(int n)
{
    // array to store binary number
    int binaryNum[1000];

    // counter for binary array
    int i = 0;
    while (n > 0) {
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        ++i;
    }

    string res;

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--) {
        string s = to_string(binaryNum[j]);
        res += s;
    }

    return res;
}

int hammingDistance(int x, int y)
{
    string first = decToBinary(x);
    string second = decToBinary(y);

    int diff = first.size() - second.size();
    int absDiff = abs(diff);

    if (first.size() < second.size()) {
        for (int i = 0; i < absDiff; ++i) {
            first.insert(0, "0");
        }
    }
    else if (first.size() > second.size()) {
        for (int i = 0; i < absDiff; ++i) {
            second.insert(0, "0");
        }
    }

    int res = 0;

    for (unsigned int i = 0; i < first.size(); ++i) {
        if (first[i] != second[i]) {
            ++res;
        }
    }

    return res;
}

int main()
{   
    cout << hammingDistance(1, 4) << endl;
    cout << hammingDistance(73, 93) << endl;
    cout << hammingDistance(1501377268, 258791155) << endl;

    return 0;
}
