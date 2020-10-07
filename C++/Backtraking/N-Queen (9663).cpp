#include <iostream>

using namespace std;
int answer = 0;
int col[16];
int n;
bool promising(int idx) {
	for (int j = 1; j < idx; j++)
	{
		if(col[j] == col[idx] || abs(col[idx] - col[j]) ==(idx - j))
			return false;
	}
	return true;
}
void backtracking(int idx)
{
	if (idx == n+1)
		answer += 1;
	else
	{
		for (int j = 1; j <= n; j++)
		{
			col[idx] = j;
			if (promising(idx))
			{
				backtracking(idx + 1);
			}
				
		}
	}
}
int main()
{
	cin >> n;	
	backtracking(1);
	cout << answer;
	return 0;
}