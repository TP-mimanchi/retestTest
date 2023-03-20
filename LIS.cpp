#include <iostream>
using namespace std;
int main()
{
    int a[7] = {0, 3, 5, 7, 1, 2, 8};
    int dp[10];
    dp[1] = 1;
    int max = 0;
    for (int i = 2; i <= 6; i++)
    {
        int _max = 0;
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j] && _max < (dp[j] + 1))
            {
                _max = dp[j] + 1;
            }
        }
        dp[i] = _max;
        if (max < _max)
            max = _max;
    }
    cout << max << endl;
    return 0;
}