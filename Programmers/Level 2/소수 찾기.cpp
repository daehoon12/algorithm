#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int arr[10000001];
bool visit[8];
bool check_number[10000001];
int answer = 0;
int t;

void backtracking(string number, string temp)
{

    if (temp != "")
    {
        int idx = stoi(temp);
        if (arr[idx] == 1 && check_number[idx] == 0)
        {
            check_number[idx] = 1;
            answer++;
        }
        
    }
    for (int i = 0; i < number.size(); i++)
    {
        if (!visit[i])
        {
            visit[i] = true;
            temp += number[i];
            backtracking(number, temp);
            temp.pop_back();
            visit[i] = false;
        }
    }
}

void eratos()
{
    for (int i = 1; i < 10000001; i++)
        arr[i] = 1;
    arr[1] = 0;
    for (int i = 2; i < 10000001; i++)
    {
        if (arr[i] == 0)
            continue;
        for (int j = i + i; j < 10000001; j += i)
        {
            if (arr[j] == 1)
                arr[j] = 0;
        }
    }
}

int main()
{
	cin >> t;
    eratos();
	for (int i = 0; i < t; i++)
	{
        string num;
        cin >> num;
        backtracking(num, "");
        memset(check_number, 0, sizeof(check_number));
        cout << answer << '\n';
        answer = 0;
	}
	return 0;
}