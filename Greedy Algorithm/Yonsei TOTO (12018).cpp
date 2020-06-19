#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
int n, m;
int answer = 0;
int main()
{
	cin >> n >> m;
	int sum = m;
	for (int i = 0; i < n; i++)
	{
		vector <int> temp;
		int people, L;
		cin >> people >> L;
		
		
		for (int i = 0; i < people; i++)
		{
			int k;
			cin >> k;
			temp.push_back(k);
		}
		sort(temp.begin(), temp.end(), greater<int>());
		if (people < L)
			v.push_back(1);
		else
		{
			v.push_back(temp[L - 1]);
		}
	}
	sort(v.begin(), v.end());
		
	for (int i = 0; i < v.size(); i++)
	{
		if (sum - v[i] < 0)
			break;
		else
		{
			sum -= v[i];
			answer++;
		}
	}
	cout << answer; 
	
	return 0; 
}
