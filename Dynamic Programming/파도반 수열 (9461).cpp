#include <iostream>

using namespace std;
long long dp[101];
/* Á¡È­½Ä : dp[n] = dp[n-1] + dp[n-5] */
int t, n;
int main()
{
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	cin >> t;	
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 6; j <= n; j++)
		{
			dp[j] = dp[j - 1] + dp[j - 5];
		}
		cout << dp[n] << '\n';
	}
	return 0;
}