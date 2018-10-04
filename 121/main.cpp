#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
    int profit = 0;

    for(unsigned int i = 0; i < prices.size(); ++i) {
        int buy = prices[i];
        for(unsigned int j = i + 1; j < prices.size(); ++j) {
            if(prices[j] > buy) {
                int tempProfit = prices[j] - buy;
                if(tempProfit > profit) {
                    profit = tempProfit;
                }
            }
        }
    }

    return profit;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    vector<int> prices2 = {7,6,4,3,1};
    cout << maxProfit(prices) << endl;
    cout << maxProfit(prices2) << endl;

    return 0;
}
