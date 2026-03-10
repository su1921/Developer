#include <iostream>
using namespace std;

int main()
{
	string str = "my name is suresh";

	int start = 0;
	int end = str.size()-1;

	while (start < end)
	{
		char ch = str[start];
		str[start] = str[end];
		str[end] = ch;

		start++;
		end--;
	}

	cout << str << endl;
}


