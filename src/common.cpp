#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void binary_search(vector<int> &arr, int target)
{
    int l = 0;
    int r = arr.size() - 1;
    int m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (arr[m] >= target && ((m - 1) >= 0 && arr[m - 1] < target || m == 0))
        {
            // 找到
            cout << m << endl;
            return;
        }
        else if (arr[m] >= target)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << -1 << endl;
}
int main(int argc, char const *argv[])
{
    vector<int> arr{1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 6, 6, 8, 10, 10, 10, 90};
    int target = 9;
    binary_search(arr, target);
    return 0;
}
