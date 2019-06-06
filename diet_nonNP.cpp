#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int W = 70;
int A = 3;
int B = 2;
int final_weight = 0;
int stressPoint = 0;
std::string plan("");

void diet_plan(const std::vector<int>& C,int currentWeight, int nthDay, int stressPoint, std::string& str)
{
  const int N = C.size() - 1;
	if (nthDay == N)
	{
		int eatWeight = currentWeight + C[nthDay];
		int notEatWeight = currentWeight - A + (++stressPoint) * B;
		if (final_weight == 0)
		{
			final_weight = std::min(eatWeight, notEatWeight);
			if (final_weight == eatWeight)
				plan = str + '1';
			
			else if (final_weight == notEatWeight)
				plan = str + '0';
		}

		else
		{
			if (eatWeight < notEatWeight && eatWeight < final_weight)
			{
				final_weight = eatWeight;
				plan = str + '1';
			}
			else if (notEatWeight < eatWeight && notEatWeight < final_weight)
			{
				final_weight = notEatWeight;
				plan = str + '0';
			}
		}
	}

	else
	{
		int weightToday_eat = currentWeight + C[nthDay];
		int weightToday_noEat = currentWeight - A + (++stressPoint) * B;
		std::string s1(str + '1');
		std::string s2(str + '0');

		diet_plan(C, weightToday_eat, nthDay + 1, 0, s1);
		diet_plan(C, weightToday_noEat, nthDay + 1, stressPoint, s2);
	}
}

int main(int argc, char* argv[])
{
  std::vector<int> C{ 4, 6, 2, 5, 3, 4, 5, 4, 1, 3, 4, 3, 2, 1, 2, 1, 4, 2, 1, 3 };
  // C{ 4, 6, 2, 5, 3, 4, 5, 4, 1, 3, 4, 3, 2, 1, 2, 1, 4, 2, 1, 3 }
	diet_plan(C, W, 0, stressPoint, plan);
	std::cout << final_weight << std::endl;
  std::cout << plan << std::endl;
	return 0;
}