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

	if (k < 5) { // K가 5 이하면 답을 구할 수 없음
		cout << 0;
		return 0;
	}
	if (k == 26) { // K가 26이면 모든 단어를 다 배울 수 있다.
		cout << n;
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		s[i] = s[i].substr(4, s[i].length()); // 4번째 위치부터 끝까지 위치의 값을 s[i]에 저장 (anta) 제거

		for (int j = 0; j < 4; j++)
		{
			s[i].pop_back(); // tica 삭제
		}
	}
	k -= 5; // 필수 단어만큼 값을 뺌
	alpha['a' - 'a'] = 1;
	alpha['c' - 'a'] = 1;
	alpha['n' - 'a'] = 1;
	alpha['t' - 'a'] = 1;
	alpha['i' - 'a'] = 1; // 필수로 있어야 하는 단어들은 방문 표시

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
		if (!alpha[i]) // 조합을 
		{
			alpha[i] = 1;
			dfs(i, cnt + 1);
			alpha[i] = 0;
		}
	}
}
