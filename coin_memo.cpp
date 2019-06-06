#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>

int min_coins(const std::vector<int>& coin_list, int amount, std::unordered_map<int, int>& memo)
{
	if (amount == 0) return 0;
	if (amount < 0) return -1;
	if (memo.find(amount) != memo.end()) return memo[amount];
	
	int min_coin = std::numeric_limits<int>::max();
	for (int coin : coin_list)
	{
		int num_of_coins = min_coins(coin_list, amount - coin, memo);
		if (num_of_coins >= 0 && num_of_coins < min_coin)
			min_coin = num_of_coins + 1;
		
		memo[amount] = (min_coin == std::numeric_limits<int>::max())? -1 : min_coin;
	}
	
	return min_coin;
}

int main()
{
	std::vector<int> availCoins { 1, 5, 10, 50 };
	std::unordered_map<int, int> memo;
	
	std::cout << min_coins(availCoins, 0, memo) << std::endl;
	return 0;
}