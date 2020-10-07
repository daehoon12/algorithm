#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
int rope[100001];
int temp[100001];
int answer = 0;
bool cmp(int a, int b);

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> rope[i];
	}
	
	sort(rope, rope + n, cmp);
	for (int i = 1; i <= n; i++)
	{
		temp[i] = rope[i-1] * i;
		answer = max(temp[i], answer);
	}
	cout << answer;
	return 0;
}

bool cmp(int a, int b)
{
	if (a > b)
		return true;
	else
		return false;

}