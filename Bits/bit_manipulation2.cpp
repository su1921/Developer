#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // count set bits
    {
        int n = 7;
        int count = 0;
        while (n)
        {
            n = n & (n-1);
            count++;
        }
        cout << "Set bits: " << count << endl;
    }

    // cancel duplicates
    {
        vector<int> v = {1, 2, 4, 2, 1};
        int result = 0;
        
        for (int i : v)
        {
            result  = result ^ i;
        }
        cout << "Unique: " << result << endl;
    }

    // swap without temp variable
    {
        int a = 5;
        int b = 7;

        cout << "a: " << a << " b: " << b << endl;
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;

        cout << "a: " << a << " b: " << b << endl;
    }

    // check opposite signs
    {
        int a = 5;
        int b = -7;

        if ((a ^ b) < 0)
        {
            cout << "opposite sign" << endl;
        }
        else
        {
            cout << "same sign" << endl;
        }
    }

    // even or odd
    {
        int n = 7;

        if ((n & 1) == 0)
        {
            cout << "even" << endl;
        }
        else
        {
            cout << "odd" << endl;
        }
    }

    // reverse bits
    {
        int n = 1342177280;
        int result = 0;

        for (int i = 0; i < 32; i++)
        {
            result <<= 1;
            result |= (n & 1);
            n >>= 1;
        }

        cout << "reverse bits: " << result << endl;   
    }

    // nibble swap
    {
        int n = 10;
        int left = (n & 0x0F) << 4;
        int right = (n & 0xF0) >> 4;

        int t = left | right;

        cout << "nibble swap: " << t << endl;
    }
}