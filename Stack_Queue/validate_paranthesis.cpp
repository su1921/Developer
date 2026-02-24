#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "({}[]()";
    stack<char> st;

    for (char ch : str)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() && ch  == ')' && st.top() == '(' ||
                ch == ']' && st.top() == '[' ||
                ch == '}' && st.top() == '{')
            {   
                st.pop();
            }
            else
            {
                cout << "Not Valid!\n";
                return 0;
            }
        }
    }

    if (st.empty())
    {
        cout << "Valid!\n";
    }
    else
    {
        cout << "Not Valid!\n";
    }
}