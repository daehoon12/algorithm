#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string convert(int n)
{
    string ret = "";
    if (n == 10)
        ret = "A";
    else if (n == 11)
        ret = "B";
    else if (n == 12)
        ret = "C";
    else if (n == 13)
        ret = "D";
    else if (n == 14)
        ret = "E";
    else if (n == 15)
        ret = "F";

    return ret;
}
string calc(int n, int t)
{
    string temp = "";
    while (true)
    {
        if (t <= 0)
            break;
        int num = t % n;
        if (num > 9)
            temp += convert(num);
        else
            temp += to_string(num);
        t = t / n;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp = "0";
    for(int i=1;i<t*m;i++)
        temp += calc(n, i);
    int cnt = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        if (i % m == p - 1)
        {
            cnt++;
            answer += temp[i];
            if (cnt == t)
                break;
        }
    }
    return answer;
}