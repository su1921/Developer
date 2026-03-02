#include <iostream>
using namespace std;

int main()
{
    int n = 8;
    int k = 2;
    int t;

    // set kth bit
    t = n | (1 << k);
    cout << "Set Kth bit: " << t << endl;

    // clear kth bit
    t = n & ~(1<<k);
    cout << "Clearn Kth bit: " << t << endl;

    // toggle kth bit
    t = n ^ (1 << k);
    cout << "Toggle Kth bit: " << t << endl;

    // check kth bit
    t = (n & (1<<k)) != 0;
    cout << "Kth bit: " << t << endl;

    // number is power of 2
    t = (n & (n-1)) == 0;
    cout << "Number is power of 2: " << t << endl;

    // lowest set bit
    t = n & (-n);
    cout << "Lowest set bit: " << t << endl;

    // remove lowest set bit
    t = n & (n-1);
    cout << "Remove lowest set bit: " << t << endl;

    // multiply by 2^k
    t = n << k;
    cout << "Multiply by 2^K: " << t << endl;

    // divided by 2^k
    t = n >> k;
    cout << "Divided by 2^K: " << t << endl;

}