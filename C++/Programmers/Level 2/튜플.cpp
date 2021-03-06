#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> tuples;
bool visit[100001];

bool cmp(string a, string b)
{
    if (a.size() < b.size())
        return true;
    else
        return false;
}

void make_tuples(string s)
{
    int tuple_idx = 0;
    string temp = "";
    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] == '{')
        {
            continue;
        }
        else if (s[i] == ',')
        {
            if (s[i + 1] == '{')
                continue;
            else
                temp += s[i];
        }
        else if (s[i] == '}')
        {
            tuples.push_back(temp);
            temp = "";
        }
        else
            temp += s[i];
    }
}

vector<int> solution(string s) {
    vector<int> answer;
    make_tuples(s);
    sort(tuples.begin(), tuples.end(), cmp);

    for (int i = 0; i < tuples.size(); i++)
    {
        string temp = "";
        for (int j = 0; j < tuples[i].size(); j++)
        {
            if (tuples[i][j] == ',')
            {
                int idx = stoi(temp);
                if (!visit[idx])
                {
                    visit[idx] = true;
                    answer.push_back(idx);
                }
                temp = "";
            }
            else
            {
                temp += tuples[i][j];
                if (j == tuples[i].size() - 1)
                {
                    int idx = stoi(temp);
                    if (!visit[idx])
                    {
                        visit[idx] = true;
                        answer.push_back(idx);
                    }
                    temp = "";
                }
            }
            }
        }
    
    return answer;
}
