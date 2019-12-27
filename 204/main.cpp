#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n)
{
    vector<bool> prime(n + 1, true);
    int p = 2;

    while (p * p <= n) {
        if (prime[p] == true) {
            for (int i = p * p; i < n + 1; i += p) {
                prime[i] = false;
            }
        }

        ++p;
    }

    int ans = 0;

    for (int i = 2; i < n; ++i) {
        if (prime[i] == true) {
            ++ ans;
        }
    }

    cout << ans << endl;

    return ans;
}

int main()
{
    countPrimes(2);
    countPrimes(3);
    countPrimes(10);

    return 0;
}
