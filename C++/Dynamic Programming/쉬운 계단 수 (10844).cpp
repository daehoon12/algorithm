#include <iostream>
#define mod 1000000000
using namespace std;
int n;
int dp[101][10];
/* Á¡È­½Ä 

0 1 2 3 4 5 6 7 8 9
1 1 1 1 1 1 1 1 1 1
1 2 2 2 2 2 2 2 2 1
2 3 4 4 4 4 4 4 3 2
3 6 7 8 8 8 8 7 6 3

if (j == 0)
	dp[i][j] = dp[i - 1][j + 1]
else if (j == 9)
	dp[i][j] = dp[i - 1][j - 1]
else
	dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])
*/
int main()
{
	int answer = 0;
	cin >> n;
	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1]%mod;
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1]%mod;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%mod;
		}
	}
	for (int i = 1; i < 10; i++)
		answer =(answer+dp[n][i])%mod;
	cout << answer%mod;
	return 0;
}