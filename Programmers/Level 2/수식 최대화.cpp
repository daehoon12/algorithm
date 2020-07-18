#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool visit[3];
vector <long long> num;
vector<int> turn;
long long answer2 = 0;
// 1. parsing
// 2. 순열 계산
// 3. 가장 큰 값 찾기

string parsing(string expression)
{
    string exp_oper = "";
    string temp = "";
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] < '0' || expression[i] > '9')
        {
            num.push_back(stoi(temp));
            exp_oper += expression[i];
            temp = "";
        }
        else
        {
            temp += expression[i];
        }
    }
    num.push_back(stoi(temp));
    return exp_oper;
}

string find_oper(string exp_oper)
{
    string kind_of_oper = "";
    bool visit2[3] = { false, };
    int idx = 0;
    for (int i = 0; i < exp_oper.size(); i++)
    {
        if (!visit2[idx] && kind_of_oper.find(exp_oper[i]) == -1)
        {
            visit2[idx++] = true;
            kind_of_oper += exp_oper[i];
        }
       /* else if (!visit2[idx] && kind_of_oper.find('-') == -1)
        {
            visit2[idx++] = true;
            kind_of_oper += exp_oper[i];
        }
       else if (!visit2[idx] && kind_of_oper.find('*') == -1)
        {
            visit2[idx++] = true;
            kind_of_oper += exp_oper[i];
        }*/
    }
    return kind_of_oper;
}
void calc(int turn, string& exp_oper, string kind_of_oper, vector <long long>& num)
{
    for (int i = 0; i < exp_oper.size(); i++)
    {
        if (exp_oper[i] == kind_of_oper[turn])
        {
            if (exp_oper[i] == '+')
            {
                num[i] += num[i + 1];
                num.erase(num.begin() + i + 1);
                exp_oper.erase(exp_oper.begin() + i);
                i--;
            }
            else if (exp_oper[i] == '-')
            {
                num[i] -= num[i + 1];
                num.erase(num.begin() + i + 1);
                exp_oper.erase(exp_oper.begin() + i);
                i--;
            } 
            else if (exp_oper[i] == '*')
            {
                num[i] *= num[i + 1];
                num.erase(num.begin() + i + 1);
                exp_oper.erase(exp_oper.begin() + i);
                i--;
            }
        }
    }
}
void go(int cnt, string kind_of_oper, string exp_oper)
{
    if (cnt == kind_of_oper.size())
    {
        vector <long long> temp_num = num;
        string temp_exp_oper = exp_oper;
       
        for (int i = 0; i < turn.size(); i++)
        {
            calc(turn[i], temp_exp_oper, kind_of_oper, temp_num);
        }
        answer2 = max(answer2, abs(temp_num[0]));
        return;
    }
    for (int i = 0; i < kind_of_oper.size(); i++)
    {
        if (!visit[i])
        {
            visit[i] = true;
            turn.push_back(i);
            go(cnt + 1, kind_of_oper, exp_oper);
            visit[i] = false;
            turn.pop_back();
        }
    }
}
long long solution(string expression) {
    long long answer = 0;
    string exp_oper = parsing(expression);
    string kind_of_oper = find_oper(exp_oper);
    go(0, kind_of_oper, exp_oper);
    answer = answer2;
    return answer;
}
