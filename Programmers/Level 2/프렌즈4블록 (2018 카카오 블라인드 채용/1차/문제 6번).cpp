#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer2 = 0;

vector <pair<int, int>> v[26];
bool check[26];
 vector<pair<int, int>> make_friends(char ch, vector<string> board)
{
    vector < pair<int, int>> temp;
    for (int y = 0; y < board.size(); y++)
    {
        for (int x = 0; x < board[y].size(); x++)
        {
            if (board[y][x] == ch)
                temp.push_back(make_pair(y,x));
        }
    }
    return temp;
}

void down_map(int m, int n, vector<string>&board)
{
    for (int t = 0; t < m-1; t++)
    {
        for (int y = 0; y < m-1; y++)
        {
            for(int x =0; x<n;x++)
                if (board[y][x] != '.' && board[y + 1][x] == '.')
                {
                    board[y + 1][x] = board[y][x];
                    board[y][x] = '.';
                }
        }
    }
}

bool delete_map(int m, int n, char ch, vector<string> &board, vector<pair<int, int>> location)
{
    vector<pair<int, int>> delete_lo;
    bool flag = false;
    for (int i = 0; i < location.size(); i++)
    {
        int x = location[i].second;
        int y = location[i].first;

        if (y >= m-1 || x >= n-1)
            continue;

        if (board[y][x + 1] == ch && board[y + 1][x] == ch && board[y + 1][x + 1] == ch)
        {
            flag = true;
            delete_lo.push_back(make_pair(y, x));
            delete_lo.push_back(make_pair(y, x + 1));
            delete_lo.push_back(make_pair(y+1, x));
            delete_lo.push_back(make_pair(y+1, x + 1));
        }
    }

    if (!delete_lo.empty())
    {
        for (int i = 0; i < delete_lo.size(); i++)
        {
            int x = delete_lo[i].second;
            int y = delete_lo[i].first;
            board[y][x] = '.';
        }
    }
    if (flag == true)
        return true;
    else
        return false;
}

int find_answer(int m, int n,vector<string> board)
{
    int cnt = 0;
    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (board[y][x] == '.')
                cnt++;
        }
    }
    return cnt;
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (true) {
        bool flag = false;
        for (int i = 0; i < 26; i++)
        {
            v[i] = make_friends('A' + i, board);
        }
        for (int i = 0; i < 26; i++)
        {
            check[i] = delete_map(m, n, 'A' + i, board, v[i]);
        }
        for (int i = 0; i < 26; i++)
        {
            if (check[i] == true)
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
            down_map(m, n, board);
        else
            break;
    }
    answer = find_answer(m, n, board);
    return answer;
}

int main()
{
    vector<string> board = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
    cout<< solution(4, 5, board);
    return 0;
}
