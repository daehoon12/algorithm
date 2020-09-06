#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class cctv_info {
public:
	int y, x, number;
	cctv_info(int y, int x, int number)
	{
		this->y = y;
		this->x = x;
		this->number = number;
	}
};


int map[9][9];
int N, M;
int answer = 987654321;
vector<cctv_info> cctv;

void copyMap(int map[][9], int temp_map[][9])
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
			map[y][x] = temp_map[y][x];
	}

}

void input()
{ 
	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> map[y][x];
			if (map[y][x] != 0 && map[y][x] != 6)
				cctv.push_back(cctv_info(y, x, map[y][x]));
		}
	}
}

void detect(int dir, int y, int x) // 북, 동, 남, 서
{
	if (dir == 0)
	{
		for (int i = y - 1; i >= 0; i--)
		{
			if (map[i][x] == 6)
				break;
			if (map[i][x] == 0)
				map[i][x] = 7;
		}
	}
	if (dir == 1)
	{
		for (int i = x + 1; i < M; i++)
		{
			if (map[y][i] == 6)
				break;
			if (map[y][i] == 0)
				map[y][i] = 7;
		}
	}
	if (dir == 2)
	{
		for (int i = y + 1; i < N; i++)
		{
			if (map[i][x] == 6)
				break;
			if (map[i][x] == 0)
				map[i][x] = 7;
		}
	}
	if (dir == 3)
	{
		for (int i = x - 1; i >= 0; i--)
		{
			if (map[y][i] == 6)
				break;
			if (map[y][i] == 0)
				map[y][i] = 7;
		}
	}

}

int find_answer()
{
	int ret = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (map[y][x] == 0)
				ret++;
		}
	}
	return ret;
}

void print_map()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cout << map[y][x] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}


void dfs(int cnt)
{
	if (cnt == cctv.size())
	{
		answer = min(answer, find_answer());
		//print_map();
		return;
	}

	int y = cctv[cnt].y;
	int x = cctv[cnt].x;
	int cc_num = cctv[cnt].number;
	int temp_map[9][9]; // temp_map을 전역으로 두면 이전에 실행했던 값이 저장되서 답이 나오지 않는다.
	copyMap(temp_map, map); // 맵의 상태를 temp_map으로 옮김

	if (cc_num == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			detect(i, y, x);
			dfs(cnt + 1);
			copyMap(map, temp_map);
		}
	}

	else if (cc_num == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			detect(i%4, y, x);
			detect((i + 2) %4, y, x);
			dfs(cnt + 1);
			copyMap(map, temp_map);
		}
	}
	else if (cc_num == 3)
	{
		for (int i = 0; i < 4; i++)
		{
			detect(i, y, x);
			detect((i + 1)%4, y, x);
			dfs(cnt + 1);
			copyMap(map, temp_map);
		}
	}
	else if (cc_num == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			detect((3 + i) % 4, y, x);
			detect(i % 4, y, x);
			detect((i + 1) % 4, y, x);
			
			dfs(cnt + 1);
			copyMap(map, temp_map);
		}
	}
	else if (cc_num == 5)
	{
		for (int i = 0; i < 4; i++)
		{
			detect(i, y, x);
		}
		dfs(cnt + 1);
		copyMap(map, temp_map);
	}
}

int main()
{
	input();
	dfs(0);
	cout << answer << '\n';
	return 0;
}
