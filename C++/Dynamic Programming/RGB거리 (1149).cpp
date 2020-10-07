#include <iostream>
#include <algorithm>

using namespace std;
int n;
int RGB[1001][4];

int answer = 987654321;

/* Á¡È­½Ä :	RGB[i][0] += min(RGB[i - 1][1], RGB[i-1][2]);
		RGB[i][1] += min(RGB[i - 1][0], RGB[i - 1][2]);
		RGB[i][2] += min(RGB[i - 1][0], RGB[i - 1][1]); */
int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> RGB[i][j];
	}

	for (int i = 1; i < n; i++)
	{
		RGB[i][0] += min(RGB[i - 1][1], RGB[i-1][2]);
		RGB[i][1] += min(RGB[i - 1][0], RGB[i - 1][2]);
		RGB[i][2] += min(RGB[i - 1][0], RGB[i - 1][1]);
	}
	answer = min(RGB[n-1][0], min(RGB[n-1][1], RGB[n-1][2]));
	cout << answer;
	return 0;
}