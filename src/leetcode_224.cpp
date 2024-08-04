#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int calculate(string s)
{
    // int ret = 0;
    // stack<string>
    // return ret;
}

int main(int argc, char const *argv[])
{
    string s = "(1+(4+5+2)-3)+(6+8)";
    int ret = calculate(s);
    cout << ret << endl;
    return 0;
}
