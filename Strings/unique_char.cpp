#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string str = "ababccdab";
    unordered_map<char, int> mp;

    for (char ch : str)
    {
        mp[ch]++;
    }

    for (char ch : str)
    {
        if (mp[ch] == 1)
        {
            cout << "Unique char: " << ch << endl;
        }
    }

}