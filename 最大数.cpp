/*
Leetcode.179
给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。

注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
示例 1：

输入：nums = [10,2]
输出："210"
示例 2：

输入：nums = [3,30,34,5,9]
输出："9534330"
*/
#include <iostream>
#include <string>

using namespace std;
int compare(int x, int y, int x1, int x2)
{
    string s1 = to_string(x);
    string s2 = to_string(y);
    string st1 = s1 + s2;
    string st2 = s2 + s1;
    if (stoi(st1) >= stoi(st2))
        return x1;
    else
        return x2;
}
int main()
{
    int n, a[101];
    string st = "";
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++) // 排序
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int index = compare(a[j], a[j + 1], j, j + 1); // 比较
            if (index != j + 1)
            {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
        st += to_string(a[i]);
    if (st[0] == '0')
        cout << "0";
    else
        cout << st;
    return 0;
}