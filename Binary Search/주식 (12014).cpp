#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


int dx[] = { 1,0,-1,0 }; // 오른쪽, 아래, 왼쪽, 위
int dy[] = { 0,1,0,-1 };



for (int i = 0; i < 4; i++)
{
	int cx = lx + dx[i];
	int cy = ly + dy[i];

	if (cx < 0 || cx >= m || cy < 0 || cy >= n)
		continue;

}

