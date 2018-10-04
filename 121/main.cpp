#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int maxProfit(vector<int>& prices) //using brute force
{
    int profit = 0;

    for(unsigned int i = 0; i < prices.size(); ++i) {
        for(unsigned int j = i + 1; j < prices.size(); ++j) {
            if(prices[j] > prices[i]) {
                int tempProfit = prices[j] - prices[i];
                if(tempProfit > profit) {
                    profit = tempProfit;
                }
            }
        }
    }

    return profit;
}

int maxProfit2(vector<int>& prices) //using one pass
{
    int minPrice = INT_MAX;
    int profit = 0;

    for(unsigned int i = 0; i < prices.size(); ++i) {
        if(prices[i] < minPrice) {
            minPrice = prices[i];
        }
        else if(prices[i] - minPrice > profit) {
            profit = prices[i] - minPrice;
        }
    }

    return profit;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    vector<int> prices2 = {7,6,4,3,1};
    cout << maxProfit2(prices) << endl;
    cout << maxProfit2(prices2) << endl;

    return 0;
}
