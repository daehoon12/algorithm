#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

string s[50];
int n, k;

int alpha[26];
void alphaInit();
int answer = 0;
void dfs(int idx, int cnt);
int main()
{
	cin >> n >> k;

	if (k < 5) {
		cout << 0;
		return 0;
	}
	if (k == 26) {
		cout << n;
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		s[i] = s[i].substr(4, s[i].length());

		for (int j = 0; j < 4; j++)
		{
			s[i].pop_back();
		}
	}
	k -= 5;
	alpha['a' - 'a'] = 1;
	alpha['c' - 'a'] = 1;
	alpha['n' - 'a'] = 1;
	alpha['t' - 'a'] = 1;
	alpha['i' - 'a'] = 1;

	dfs(0, 0);
	cout << answer;
}

void dfs(int idx, int cnt)
{
	if (cnt == k)
	{
		int temp = 0;
	
		for (int i = 0; i < n; i++)
		{
			bool flag = true;
			for (int j = 0; j < s[i].size(); j++)
			{
				int idx = s[i][j] - 'a';
				if (alpha[idx] == 0)
				{
					flag = false;
					break;
				}
			}
			if (flag)
				temp++;
		}
		answer = max(answer, temp);
		return;
	}

	for (int i = idx; i < 26; i++)
	{
		if (!alpha[i])
		{
			alpha[i] = 1;
			dfs(i, cnt + 1);
			alpha[i] = 0;
		}
	}
}