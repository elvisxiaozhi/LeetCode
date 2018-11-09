#include <iostream>

using namespace std;

int hammingWeight(uint32_t n)
{
    int res = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            ++res;
        }
        n = n / 2;
    }

    return res;
}

int main()
{
    cout << hammingWeight(11) << endl;
    return 0;
}
