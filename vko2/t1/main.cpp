#include <iostream>

using namespace std;

void printYlaosa(int);
void printAlaosa(int);

int main()
{
	int tahdet;

	cout << "Anna tahtien maksimimaara : ";
	cin >> tahdet;

	printYlaosa(tahdet);
	printAlaosa(tahdet);

	system("pause");
	return 0;
}

void printYlaosa(int tahdet)
{
	int loop = tahdet;
	for (int i = 0; i < tahdet; i++)
	{
		for (int j = 0; j < loop; j++)
		{
			cout << "*";
		}
		loop--;
		cout << endl;
	}
	return;
}

void printAlaosa(int tahdet)
{
	int loop = 2;
	for (int i = 0; i < tahdet - 1; i++)
	{
		for (int j = 0; j < loop; j++)
		{
			cout << "*";
		}
		loop++;
		cout << endl;
	}
	return;
}