#include <iostream>
#include <string>
using namespace std;
string ip = "";
string sip[4] = {"", "", "", ""};

void dfs(int n, string &st, int k)
{
    if (n == 4)
    {
        ip = sip[0] + "." + sip[1] + "." + sip[2] + "." + sip[3];
        if (ip.size() == st.size() + 3)
            cout << ip << endl;
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        string s = st.substr(k, i);
        // cout << s << endl;
        if (s[0] == '0')
        {
            sip[n] = "0";
            dfs(n + 1, st, k + i);
            sip[n] = ""; // 回溯
            break;
        }
        else
        {
            int x = 0;
            for (int j = 0; j < i; j++)
                x = x * 10 + (s[j] - '0');
            if (x > 0 && x <= 255)
            {
                sip[n] = s;
                dfs(n + 1, st, k + i);
                sip[n] = ""; // 回溯
            }
        }
    }
}
int main()
{
    string st;
    cin >> st;
    // cout << st << endl;
    dfs(0, st, 0);
    // cout << st << endl;

    return 0;
}