#include <iostream>

using namespace std;

int min(int, int);
int min(int, int, int);
int min(int, int, int, int);

int main()
{
	int luvut[4];
	int lkmaara;

	cout << "Montako numeroa haluat antaa (2-4)?: ";
	cin >> lkmaara;

	if (lkmaara >= 2 && lkmaara <= 4)
	{
		for (int i = 0; i < lkmaara; i++)
		{
			cout << "Anna luku " << i + 1 << ": ";
			cin >> luvut[i];
		}
	}

	if (lkmaara == 2)
	{
		cout << "Pienin luku on: " << min(luvut[0], luvut[1]) << endl;
	}
	else if (lkmaara == 3)
	{
		cout << "Pienin luku on: " << min(luvut[0], luvut[1], luvut[2]) << endl;
	}
	else if (lkmaara == 4)
	{
		cout << "Pienin luku on: " << min(luvut[0], luvut[1], luvut[2], luvut[3]) << endl;
	}
	else
		cout << "Virheellinen valinta" << endl;

	system("pause");
	return 0;
}

int min(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	else
		return y;
}

int min(int x, int y, int z)
{
	if (z < min(x, y))
	{
		return z;
	}
	else
		return min(x, y);
}

int min(int x, int y, int z, int w)
{
	if (w < min(x, y, z))
	{
		return w;
	}
	else
		return min(x, y, z);
}