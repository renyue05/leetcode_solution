#include <iostream>
#include <vector>
using namespace std;
bool isOrdered(const vector<int> &arr)
{
    int n = -1;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] < n)
        {
            return false;
        }
        n = arr[i];
    }
    return true;
}
vector<int> pancakeSort(vector<int> &arr)
{
    vector<int> ret;
    while (true)
    {
        int l = 1;
        while (l < arr.size() && arr[l] >= arr[l - 1])
        {
            ++l;
        }   
        // l是

        // for (i = 1; i < arr.size(); ++i)
        {
        }
    }

    return ret;
}
int main(int argc, char const *argv[])
{
    vector<int> numbers{3, 2, 4, 1, 5, 0};
    auto ret = pancakeSort(numbers);
    for (auto i : ret)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << isOrdered(numbers) << endl;
    return 0;
}
