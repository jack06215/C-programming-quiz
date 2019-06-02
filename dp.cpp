#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(const std::vector<int>& prices)
{
    if (prices.size() < 1) return 0;
    int max_profit = 0;
    int min_price = prices[0];

    for (int price : prices)
    {
        min_price = std::min(min_price, price);
        max_profit = std::max(max_profit, price - min_price);
    }
    
    return max_profit;
}

int main()
{
    std::vector<int> stocks = { 7, 1, 5, 3, 6, 4  };
    std::cout << maxProfit(stocks) << std::endl; 

    return 0;
}
