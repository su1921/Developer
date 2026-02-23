#include <iostream>
using namespace std;

int main()
{
    int num = 12345321;
    int original = num;
    int reverse = 0;

    while (num > 0)
    {
        int digit = num%10;
        reverse = reverse*10 + digit;
        num = num/10;
    }

    if (reverse == original)
    {
        cout << "Palindrome!\n";
    }
    else
    {
        cout << "Not a Palindrome!\n";
    }

}