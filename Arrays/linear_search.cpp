#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 3, 2, 4, 5, 7};
    int target = 10;

    for (int i = 0; i < 6; i++)
    {
        if (target == arr[i])
        {
            cout << "Target found!\n";
            return 0;
        }
    }

    cout << "Target Not found!\n";

    cout << "size: " << sizeof(arr)/sizeof(arr[0]);
}