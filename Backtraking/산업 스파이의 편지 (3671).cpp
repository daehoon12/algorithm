#include <iostream>
#include <string>
#include <cstring>

#define MAX 10000000
bool numbers[MAX];
bool visitNum[MAX];
bool visit[8];
using namespace std;
int t;
int answer = 0;

void init()  // 에라토스테네스의 체
{
	for (int i = 2; i < MAX; i++) 
	{
		if (numbers[i] == true)
			continue;
		
		for (int j = i + i; j < MAX; j += i)
			numbers[j] = true;
	}
	
}

void backtracking(int cnt, string s, string temp)
{
	
	if (temp != "")
	{
		int num = stoi(temp);
		if (num > 1 && num < MAX && visitNum[num]==false)
		{
			visitNum[num] = true;

			if (numbers[num] == false)
				answer++;
			
		}
	}

	if (temp.size() == s.size())
		return;

	for (int i = 0; i < (int)s.size(); i++)
	{
		if (!visit[i]) 
		{
			visit[i] = true;
			temp += s[i];
			backtracking(cnt + 1, s, temp);
			temp.pop_back();
			visit[i] = false;
		}
	}
}
int main()
{
	init();
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string s;
		cin >> s;
		memset(visitNum, false, sizeof(visitNum));
		backtracking(0, s, "");
		cout << answer << '\n';
		answer = 0;
	}
	return 0;
}

