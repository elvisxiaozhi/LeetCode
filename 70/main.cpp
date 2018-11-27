#include <iostream>
#include <vector>

using namespace std;

int climbStair(int i, int n)
{
    if(i > n) {
        return 0;
    }
    if(i == n) {
        return 1;
    }

    return climbStair(i + 1, n) + climbStair(i + 2, n);
}

int climbStairs(int n)
{
    int ways = climbStair(0, n);
    return ways;
}

int climbStairs1(int n)
{
    if (n == 1) {
        return 1;
    }

    int first = 1;
    int second = 2;

    for (int i = 3; i <= n; i++) {
       int third = first + second;
       first = second;
       second = third;
    }

    return second;
}

int main()
{
    cout << climbStairs1(40) << endl;
    return 0;
}
