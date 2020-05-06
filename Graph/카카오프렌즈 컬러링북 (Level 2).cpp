#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int number_of_area = 0;
int max_size_of_one_area = 0;

int cnt = 0;
void dfs(long long number, int y, int x, int m, int n, vector<vector<int>> picture, bool visit[100][100])
{
    
    for (int i = 0; i < 4; i++)
    {
        int cx = dx[i] + x;
        int cy = dy[i] + y;
        if (cx < 0 || cy < 0 || cy >= m || cx >= n || picture[cy][cx] == 0)
            continue;
        if (picture[cy][cx] == number && !visit[cy][cx])
        {
            visit[cy][cx] = true;
            cnt++;
            dfs(number, cy, cx, m,n, picture,visit);
            
        }
   }
    if (max_size_of_one_area < cnt)
    {
        max_size_of_one_area = cnt;
  }

}
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    bool visit[100][100] = { false, };
    number_of_area = 0;
    max_size_of_one_area = 0;
    for (int y = 0; y < picture.size(); y++)
    {
        for (int x = 0; x < picture[y].size(); x++)
        {
            if (picture[y][x] != 0)
            {
                if (!visit[y][x])
                {
                    visit[y][x] = true;
                    cnt++;
                    dfs(picture[y][x], y, x, m, n, picture, visit);
                    number_of_area++;
                    cnt = 0;
                }
            }
        }
    }
        vector<int> answer(2);
        answer[0] = number_of_area;
        answer[1] = max_size_of_one_area;
        return answer;
 }
int main()
{
    vector<vector<int>> picture = { {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
 {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
 {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
 {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
 {0, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0},
 {0, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 0},
 {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
 {0, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 0},
 {0, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 0},
 {0, 0, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0, 0},
 {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
 {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0} };
    vector <int> answer = solution(13, 16, picture);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}
