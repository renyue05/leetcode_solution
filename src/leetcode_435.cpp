#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int ret = 0;
    return ret;
}

int main()
{
    vector<vector<int>> intervals{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    sort(intervals.begin(), intervals.end(), [](vector<int> vec1, vector<int> vec2)
         { return vec2[1] > vec1[1]; });
    cout << "1" << endl;
    return 0;
}
