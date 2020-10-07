#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int N, L;
vector<int> v;

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int max_num = 0;
		int min_num = 0;
		v.clear();
		cin >> L >> N;
		for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			max_num = max(max(v[i] , L - v[i]), max_num);
			min_num = max(min(v[i], L - v[i]), min_num); // 이걸 못 구했는데..  개미가 빨리 떨어지는 값의 최대값은 결국 모든 개미가 떨어질 수 있는 최소값이 된다.
		}
		cout << min_num << " " << max_num <<'\n';
	}
	return 0;
}
