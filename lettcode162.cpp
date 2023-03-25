/*
寻找峰值
*/
#include <iostream>
using namespace std;

int main()
{
    int nums[4] = {1, 2, 3, 1};
    int i = 0, j = 3;
    while (i < j)
    {
        int mid = (i + j) / 2;
        if (nums[mid] > nums[mid + 1])
            j = mid;
        else
            i = mid + 1;
    }
    cout << i;
    return 0;
}