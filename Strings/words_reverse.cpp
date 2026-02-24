#include <iostream>
using namespace std;

int main()
{
    string str = "my name is suresh";

    reverse(str.begin(), str.end());

    int start = 0;

    for (int end = 0; end <= str.size(); end++)
    {
        if (str[end] == ' ' || end == str.size())
        {
            reverse(str.begin()+start, str.begin()+end);
            start = end+1;
        }
    }

    cout << str << endl;
}