#include <iostream>
#include <string>
using namespace std;

int gcd_recursive(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd_recursive(b, a % b);
    }
}
string gcdOfStrings(string str1, string str2)
{
    string s = "";
    int len1 = str1.size();
    int len2 = str2.size();
    int len = gcd_recursive(len1, len2);
    string tmp = str1.substr(0, len);
    for (int i = 0; i < len1; i += len)
    {
        if (str1.substr(i, len) != tmp)
        {
            return "";
        }
    }
    for (int i = 0; i < len2; i += len)
    {
        if (str2.substr(i, len) != tmp)
        {
            return "";
        }
    }
    return tmp;
}
int main(int argc, char const *argv[])
{
    string s1 = "ABCABC";
    string s2 = "ABC";
    cout << "s1.size() : " << s1.size() << endl;
    cout << "s2.size() : " << s2.size() << endl;
    // cout << gcdOfStrings(s1, s2) << endl;
    // cout << gcd_recursive(32, 64) << endl;
    cout << gcdOfStrings(s1, s2) << endl;
    return 0;
}
// abcdabcdabcd
// abcdabcd