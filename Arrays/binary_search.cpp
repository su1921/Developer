#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1, 3, 4, 5, 6, 9};
    int target = 6;

    int low = 0;
    int high = v.size();

    while (low < high)
    {
        int mid = (low + high)/2;

        if (v[mid] == target)
        {
            cout << "Target found!\n";
            return 0;
        }
        else if (v[mid] < target)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    cout << "Target not found!\n";
}