#include <iostream>
#include <algorithm>

using namespace std;

string s[1001] = { "" ,};
int n, m;
int alpha[4];
int findMax();
void alphaInit();
int minNum = 987654321;
string answer = "";
int cnt = 0;
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[j][i] == 'A')
			{
				alpha[0]++;
			}
			else if (s[j][i] == 'C')
			{
				alpha[1]++;
			}
			else if (s[j][i] == 'G')
			{
				alpha[2]++;
			}
			else if (s[j][i] == 'T')
			{
				alpha[3]++;
			}
		}
		int tempIdx = findMax();

		if (tempIdx == 0)
			answer += 'A';
		else if (tempIdx == 1)
			answer += 'C';
		else if (tempIdx == 2)
			answer += 'G';
		else if (tempIdx == 3)
			answer += 'T';
	}

	
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < answer.size(); j++) {
			if (answer[j] != s[i][j])
				cnt++;
		}
	}
	cout << answer << endl;
	cout << cnt;
	return 0;
}

int findMax()
{
	int maxNum = 0;
	int idx = 0;
	for (int i = 0; i < 4; i++)
	{
		if (maxNum < alpha[i])
		{
			maxNum = alpha[i];
			idx = i;
		}

	}
	alphaInit();
	return idx;
}

void alphaInit()
{
	for (int i = 0; i < 4; i++)
	{
		alpha[i] = 0;
	}
}