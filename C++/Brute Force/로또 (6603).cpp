#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k; 
vector <int> s,idx;
int main()
{

	while (true)
	{
		cin >> k;
		if (k == 0)
			break;

		for (int i = 0; i < k; i++)
		{
			int num;
			cin >> num;
			s.push_back(num);
		}

		sort(s.begin(), s.end());

		for (int i = 0; i < 6; i++) // 1의 숫자만큼 뽑음.
		{
			idx.push_back(1);
		}
		for (int i = 0; i < s.size() -6; i++)
		{
			idx.push_back(0);
		}

		sort(idx.begin(), idx.end(), greater<int>());

		do
		{
			for (int i = 0; i < s.size(); i++)
			{
				if (idx[i] == 1)
					cout << s[i] << " ";
			}
			cout << endl;

		} while (next_permutation(idx.begin(), idx.end(), greater<int>()));

		cout << endl;
		
		while (!idx.empty())
		{
			idx.pop_back();
		}

		while (!s.empty())
		{
			s.pop_back();
		}
	}

	return 0;
}