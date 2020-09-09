#include <iostream>
#include <vector>

using namespace std;

/* 경우의 수 6C2 = 15
A VS B C D E F
B VS C D E F
C VS D E F
D VS E F
E VS F
*/

int arr1[] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };
int arr2[] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 }; // 경우의 수


int answer = 0;
int result[6][3];
int match[6][3];

void input()
{
	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cin >> match[y][x];
		}
	}
}

void dfs(int cnt)
{

	if (cnt == 15)
	{
		if (answer == 1)
			return;
		else
		{
			for (int y = 0; y < 6; y++)
			{
				for (int x = 0; x < 3; x++)
				{
					if (result[y][x] != match[y][x])
						return;
				}
			}
		}
		answer = 1;
		return;
	}


	// 시간 복잡도 : O(3^15)
	int team1 = arr1[cnt];
	int team2 = arr2[cnt];

	result[team1][0]++;
	result[team2][2]++;
	dfs(cnt+1);
	result[team1][0]--;
	result[team2][2]--;

	result[team1][1]++;
	result[team2][1]++;
	dfs(cnt+1);
	result[team1][1]--;
	result[team2][1]--;

	result[team1][2]++;
	result[team2][0]++;
	dfs(cnt+1);
	result[team1][2]--;
	result[team2][0]--;
}
int main()
{
	for (int i = 0; i < 4; i++) 
	{
		input();
		dfs(0);
		cout << answer << '\n';
		answer = 0;
	}
	return 0;
}
