#include <iostream>
#include <string>
using namespace std;
bool isVowel(char c)
{
    bool flag = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    cout << c << " " << flag << endl;
    return flag;
}
string reverseVowels(string s)
{
    int left = 0;
    int right = s.size() - 1;
    while (left < right)
    {
        while (left < s.size() && !isVowel(s[left]))
        {
            left++;
        }
        cout << "left : " << left << endl;
        while (right >= 0 && !isVowel(s[right]))
        {
            right--;
        }
        cout << "right : " << right << endl;
        if (left < right)
        {
            cout << "=============\n";
            cout << left << "  " << right << endl;
            cout << "=============\n";
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            ++left;
            --right;
            cout << s << endl;
        }
        else
        {
            break;
        }
    }
    return s;
}
int main(int argc, char const *argv[])
{
    string s = "leetcode";
    cout << reverseVowels(s) << endl;
    // cout << isVowel('a') << endl;
    // cout << isVowel('e') << endl;
    // cout << isVowel('i') << endl;
    // cout << isVowel('o') << endl;
    // cout << isVowel('u') << endl;
    return 0;
}
