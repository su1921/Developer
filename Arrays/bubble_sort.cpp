#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1, 4, 3, 2, 5};

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
            }
        }
    }

    for (int k : v)
    {
        cout << k << " ";
    }
    cout << endl;
}