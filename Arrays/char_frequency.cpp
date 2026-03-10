#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    string str = "my name is suresh";
    unordered_map<char, int> mp;

    for (char ch : str)
    {
        mp[ch]++;
    }

    for (auto j : mp)
    {
        cout << j.first << ": " << j.second << endl;
    }

}