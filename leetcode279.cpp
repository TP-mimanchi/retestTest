/*
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

示例 1：

输入：n = 12
输出：3
解释：12 = 4 + 4 + 4


*/
#include <iostream>
using namespace std;

int main()
{
    int num = 12;
    int dp[13]; // dp解法：dp[i]表示整数i所需完全平方数的最小数量
    dp[0] = 0;
    for (int i = 1; i <= 12; i++)
    {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++)
        {
            if (dp[i] > dp[i - j * j])
                dp[i] = dp[i - j * j] + 1;
        }
    }
    cout << dp[12];
    return 0;
}