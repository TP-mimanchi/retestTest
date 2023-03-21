#include <bits/stdc++.h>
using namespace std;

int abs(int n)
{
    if (n < 0)
        return n - 2 * n;
    return n;
}

int main()
{
    int n, target;
    int a[101];
    cin >> n >> target;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // int minSum = 110011;
    // int Min = 0;
    // for (int i = 0; i < n - 2; i++)
    //     for (int j = i + 1; j < n - 1; j++)
    //         for (int k = j + 1; k < n; k++)
    //         {
    //             int sum = a[i] + a[j] + a[k];
    //             if (abs(minSum) > abs(target - sum))
    //             {
    //                 minSum = target - sum;
    //                 Min = sum;
    //             }
    //         }
    // cout << Min;

    // 双指针
    int minSum = a[0] + a[1] + a[2];
    sort(a, a + n);

    for (int i = 0; i < n; i++)
    {
        int start = i + 1, end = n - 1;
        while (start < end)
        {
            int sum = a[i] + a[start] + a[end];
            if (abs(target - minSum) > abs(target - sum))
                minSum = sum;
            if (sum > target)
                --end;
            else if (sum < target)
                ++start;
            else
                break;
        }
        if (start < end)
            break;
    }
    cout << minSum;
    return 0;
}