#include <string>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

void map_init(map<string, int> & m)
{

    for (int i = 0; i < 26; i++)
    {
        string ch = "";
        ch+= 'A' + i;
        m[ch] = i + 1;
    }
}

bool check(string s, map<string, int>& m)
{
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->first == s)
            return true;
    }
    return false;
}
vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int > m;
    map_init(m);
    string temp = "";
    int temp_answer = 0;
    int idx = 27;
    for (int i = 0; i< msg.size(); i++)
    {
        temp += msg[i];
        if (check(temp, m))
        {
            temp_answer = m[temp];
        }
        else
        {
            answer.push_back(temp_answer);
            m[temp] = idx++;
            temp = "";
            i--;
        }
    }
    return answer;
}
