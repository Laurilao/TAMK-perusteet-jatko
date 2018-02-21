#include <iostream>

using namespace std;

int main()
{
	int a[10] = { 0 };
	int* b[10] = { 0 };

	int* a_ptr = a;

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		*a_ptr = i;
		b[i] = a_ptr;
		a_ptr++;
	}

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		cout << *b[i] << endl;
	}

	system("pause");
	return 0;
}