#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        int num = arr1[i] | arr2[i];
        temp.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {
        string answer_temp = "";
        string s = "";
        while (true)
        {
            if (temp[i] <=0)
                break;
            s += to_string(temp[i] % 2);
            temp[i] /= 2;
        }
        reverse(s.begin(), s.end());
        if (s.size() < n)
            answer_temp += ' ';
        for (int i = 0; i < s.size();i++)
        {
            if (s[i] == '1')
                answer_temp += '#';
            else
                answer_temp += ' ';
        }
        answer.push_back(answer_temp);
    }

    return answer;
}

int main()
{
    vector<int> arr1 = { 0,0,0,0,0 };
    vector<int> arr2 = {30,1,21,17,28 };
    vector<string> answer = solution(5, arr1, arr2);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
            cout << answer[i][j];
        cout << '\n';
    }
    return 0;
}