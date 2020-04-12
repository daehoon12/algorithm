#include <iostream>

using namespace std;
int map[129][129];
int n;
int answer = 0;
void div_conq(int x, int y, int n);
int w_cnt = 0;
int b_cnt = 0;	
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
	div_conq(0, 0, n);
	cout << w_cnt << endl;
	cout << b_cnt << endl;
	return 0;
}
void div_conq(int x, int y, int n)
{
	int cnt = 0;
	for (int i = y; i < y+n; i++)
	{
		for (int j = x; j <x+ n; j++)
		{
			if (map[i][j] == 1)
				cnt++;
		}
	}

	if (cnt == n * n)
		b_cnt++;
	else if (cnt == 0)
		w_cnt++;	
	else
	{
		div_conq(x, y, n / 2);
		div_conq(x, y + n/2, n / 2);
		div_conq(x + n/2, y + n / 2, n / 2);
		div_conq(x +n/2, y, n / 2);
	}
	return;
}