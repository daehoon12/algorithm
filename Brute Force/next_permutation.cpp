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

	//����

	cout << "���� ��� " << endl;
	while (next_permutation(v.begin(), v.end()))
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
		cnt++;
	}
	cout << cnt << endl;
	cnt = 1;

	// ����

	vector <int> ind; // 0�� 1�� ���� ����
	int k = 4; //6C4�� ���� ������

	for (int i = 0; i < k; i++) // 4���� 1 �߰�
		ind.push_back(1);
	for (int i = 0; i < v.size() - k; i++) // 2���� 0 �߰�
		ind.push_back(0);

	sort(ind.begin(), ind.end(), greater<int>()); // ����
	cout << "���� ��� " << endl;

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