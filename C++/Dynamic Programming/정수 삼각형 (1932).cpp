#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;
int n;
vector<int> dp[501];
void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int k;
			cin >> k;
			dp[i].push_back(k);
		}
	}

}
int main()
{
	
	input();
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < dp[i].size(); j++)
		{
			if (j == 0)
				dp[i][j] += dp[i - 1][j];
			else if (j == dp[i].size() - 1)
				dp[i][j] += dp[i - 1][j - 1];
			else
				dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		if (answer < dp[n - 1][i])
			answer = dp[n - 1][i];
	}
	cout << answer;
	return 0;
}