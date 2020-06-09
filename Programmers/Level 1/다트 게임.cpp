#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> temp;
    int idx = 0;
    string s = "";
    for (int i = 0; i < dartResult.size(); i++)
    {
        if (dartResult[i] == 'S')
        {
            int num = stoi(s);
            int num2= pow(num, 1);
            temp.push_back(num2);
            idx++;
            s = "";
        }
        else if (dartResult[i] == 'D')
        {
            int num = stoi(s);
            int num2 = pow(num, 2);
            temp.push_back(num2);
            idx++;
            s = "";
        }
        else if (dartResult[i] == 'T')
        {
            int num = stoi(s);
            int num2 = pow(num, 3);
            temp.push_back(num2);
            idx++;
            s = "";
        }
        else if (dartResult[i] == '*')
        {
            temp[idx-1] *= 2;
            if (idx > 1)
            {
                temp[idx - 2] *= 2;
            }
        }
        else if (dartResult[i] == '#')
        {
            int num = temp[temp.size() - 1];
            temp.pop_back();
            temp.push_back(num * -1);
        }
        else
        {
            s += dartResult[i];
        }
    }
    for (int i = 0; i < temp.size(); i++)
        answer += temp[i];
    return answer;
}
