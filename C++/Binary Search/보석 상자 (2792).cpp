#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long > v;
bool check(long long mid);
long long n, m;
int main() {

	long long answer = 987654321;
	cin >> n >> m;
	long long sum = 0;
	for (int i = 0; i < m; i++)
	{
		long long k;
		cin >> k;
		v.push_back(k);
		sum += k;
	}
	
	long long low = 0;
	long long high = sum;
	while (true)
	{
		if (low > high)
			break;
		long long mid = (low + high) / 2;
		if (check(mid)) {
			answer = min(answer, mid);
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	cout << answer;
	return 0;
}


bool check(long long mid) {
	long long cnt = 0;

	for (int i = 0; i < v.size(); i++)
	{
		cnt += v[i] / mid;
		if (v[i] % mid != 0)
			cnt++;
	}
	return n >= cnt;
}