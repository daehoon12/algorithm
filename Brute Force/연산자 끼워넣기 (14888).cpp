#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int operations[4];
vector<int> v;
int minNum = 987654321;
int maxNum = 0;
int operationsNum = 0;
void dfs(int plus, int minus, int multiply, int divide, int sum, int cnt)
{
	for (int i = 0; i < 4; i++)
	{
		if (plus < 0 || minus < 0 || multiply < 0 || divide < 0)
			return;
	}
	if (cnt == operationsNum+1)
	{
		minNum = min(minNum, sum);
		maxNum = max(maxNum, sum);
		return;
	}
	
	dfs(plus - 1, minus, multiply, divide, sum + v[cnt], cnt + 1);
	dfs(plus, minus-1, multiply, divide, sum - v[cnt], cnt + 1);
	dfs(plus, minus, multiply-1, divide, sum * v[cnt], cnt + 1);
	dfs(plus, minus, multiply, divide-1, sum / v[cnt], cnt + 1);


}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		v.push_back(k);
	}
	cin >> operations[0] >> operations[1] >> operations[2] >> operations[3];
	for (int i = 0; i < 4; i++)
	{
		operationsNum += operations[i];
	}
	dfs(operations[0], operations[1], operations[2], operations[3], v[0],1);
	cout << maxNum << '\n';
	cout << minNum << '\n';
	return 0;
}