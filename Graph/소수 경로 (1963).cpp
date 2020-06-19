#include <iostream>
#include <queue>
#include <string>

using namespace std;

int t;
int arr[10001];

queue<string> q;

void eratos()
{
	for (int i = 1; i < 10000; i++)
	{
		arr[i] = 0;
	}
	for (int i = 2; i < 10000; i++)
	{
		if (arr[i] == -1)
			continue;
		for (int j = i + i; j < 10000; j += i)
		{
			if(arr[j]==0)
				arr[j] = -1;
		}
	}
} 

bool bfs(string start_num, string end_num) 
{
	q.push(start_num);
	arr[stoi(start_num)] = 0;
	while (!q.empty())
	{
		string temp = q.front();
		q.pop();
		if (temp == end_num)
		{
			return true;
		}
		for (int i = 3; i >= 0; i--)
		{
			string temp2 = temp;
			for (int j = 0; j < 10; j++)
			{
				temp2.erase(temp2.begin() + i);
				char ch = j + '0';
				temp2.insert(temp2.begin() + i, ch);
				if (temp2 == temp)
					continue;
				int idx = stoi(temp2);
				if (stoi(temp2) >= 1000 && arr[idx] == 0)
				{
					arr[idx] = arr[(stoi(temp))] + 1;
					q.push(temp2);
				}
			}
		}
	}
	return false;
}

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string start_num, end_num;
		cin >> start_num >> end_num;
		eratos();
		if (bfs(start_num, end_num))
			cout << arr[stoi(end_num)] << '\n';
		else
			cout << "Impossble" << '\n';
		while (!q.empty())
			q.pop();
	}
	return 0;
}
