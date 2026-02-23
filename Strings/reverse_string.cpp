#include <iostream>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int left = 0;
    int right = str.size() - 1;

    while (left < right)
    {
        char ch = str[left];
        str[left] = str[right];
        str[right] = ch;

        left++;
        right--;
    }

    cout << str << "\n";
}