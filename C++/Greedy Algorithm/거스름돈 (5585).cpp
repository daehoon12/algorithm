#include <iostream>

using namespace std;

int coins[] = { 500,100,50,10,5,1 };
int n;
int answer = 0;
int main()
{
	cin >> n;
	int change = 1000 - n;
	while (true)
	{
		if (change <= 0)
			break;
		for (int i = 0; i < 6; i++)
		{
			if (change >= coins[i])
			{
				answer++;
				change -= coins[i];
				break;
			}
		}
	}

	cout << answer;
	return 0;
}