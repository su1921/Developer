#include <iostream>
using namespace std;

int main()
{
    string str = "abcdcba";
    string temp(str.rbegin(), str.rend());

    if (str == temp)
    {
        cout << "Palindrom!\n";
    }
    else
    {
        cout << "Not a palindrom!\n";
    }
}