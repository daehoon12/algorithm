#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;
int cnt = 1;
bool desc(int a, int b) {
	return a > b;
}


int main()
{

	for (int i = 0; i < 6; i++)
	{
		v.push_back(i + 1);

	}
	sort(v.begin(), v.end());

	//순열

	cout << "순열 출력 " << endl;
	while (next_permutation(v.begin(), v.end()))
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
		cnt++;
	}
	cout << cnt << endl;
	cnt = 1;

	// 조합

	vector <int> ind; // 0과 1을 담을 벡터
	int k = 4; //6C4를 만들 예정임

	for (int i = 0; i < k; i++) // 4개의 1 추가
		ind.push_back(1);
	for (int i = 0; i < v.size() - k; i++) // 2개의 0 추가
		ind.push_back(0);

	sort(ind.begin(), ind.end(), greater<int>()); // 정렬
	cout << "조합 출력 " << endl;

	while (next_permutation(ind.begin(), ind.end(), greater<int>()))
	{
		for (int i = 0; i < v.size(); i++)
			if (ind[i] == 1)
			{
				cout << v[i] << " ";
			}
		cout << endl;
		cnt++;
	}
	cout << cnt;
	return 0;
}