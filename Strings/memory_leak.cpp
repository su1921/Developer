#include <iostream>
using namespace std;

int main()
{
    int *ptr = new int[1000000000];
    delete[] ptr;
    ptr = nullptr;

}