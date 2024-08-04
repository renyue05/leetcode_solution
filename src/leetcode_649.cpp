#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

string predictPartyVictory(string senate)
{
    // int Radiant = 0;
    // int Dire = 0;
    queue<int> Radiant;
    queue<int> Dire;
    vector<int> v;
    
    int n = senate.size();
    for (int i = 0; i < senate.size(); ++i)
    {
        if (senate[i] == 'R')
        {
            Radiant.push(i);
        }
        else
        {
            Dire.push(i);
        }
    }
    while (!(Radiant.empty() || Dire.empty()))
    {
        if (Radiant.front() < Dire.front())
        {
            Radiant.push(Radiant.front() + n);
        }
        else
        {
            Dire.push(Dire.front() + n);
        }
        Radiant.pop();
        Dire.pop();
    }

    if (Radiant.empty())
    {
        return "Dire";
    }
    else
    {
        return "Radiant";
    }
}
int main(int argc, char const *argv[])
{
    string senate = "RD";
    cout << predictPartyVictory(senate) << endl;
    return 0;
}
