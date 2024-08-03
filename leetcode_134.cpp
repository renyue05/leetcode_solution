#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int start = 0;
    while (start < gas.size())
    {
        int p1 = start;
        int left_gas = gas[p1];
        while (left_gas >= cost[p1])
        {
            left_gas = left_gas - cost[p1] + gas[(p1 + 1) % gas.size()];
            p1 = (p1 + 1) % gas.size();
            if (p1 == start)
            {
                return start;
            }
        }
        start++;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    vector<int> gas{2, 3, 4};
    vector<int> cost{3, 4, 3};
    int ret = canCompleteCircuit(gas, cost);
    cout << ret << endl;

    
    return 0;

}
