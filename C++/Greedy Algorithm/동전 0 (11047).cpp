#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> coins;
int cnt = 0;
int n, k;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int coin;
		cin >> coin;
		coins.push_back(coin);
	}
	sort(coins.begin(), coins.end(), greater<int>());

	while (true)
	{
		if (k <= 0)
		{
			cout << cnt;
			return 0;
		}
		for (int i = 0; i < coins.size(); i++)
		{
			if (coins[i] <= k)
			{
				cnt++;
				k -= coins[i];
				break;
			}
		}
	}
	return 0;
}