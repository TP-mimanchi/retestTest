#include <iostream>
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
    int minSum = 110011;
    int Min = 0;
    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
            {
                int sum = a[i] + a[j] + a[k];
                if (abs(minSum) > abs(target - sum))
                {
                    minSum = target - sum;
                    Min = sum;
                }
            }
    cout << Min;
    return 0;
}