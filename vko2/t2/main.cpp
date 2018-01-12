#include <iostream>
#include <cmath>

using namespace std;

void printResult(double, double, double, double);

int main()
{
	double a, b, c, x;

	cout << "Anna arvo a: ";
	cin >> a;
	cout << "Anna arvo b: ";
	cin >> b;
	cout << "Anna arvo c: ";
	cin >> c;
	cout << "Anna arvo x: ";
	cin >> x;

	printResult(a, b, c, x);

	system("pause");
	return 0;
}

void printResult(double a, double b, double c, double x)
{
	double y = a * pow(x, 2) + b * x + c;

	cout << "Y-arvo: " << y << endl;

	return;
}