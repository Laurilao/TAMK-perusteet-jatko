#include <iostream>

using namespace std;

// Argc = annettujen argumenttien m‰‰r‰, argv[] = argumentit merkkijonoina
int main(int argc, const char* argv[])
{
	// argc = aina v‰hint‰‰n 1
	// argv[0] = sovelluksen nimi, lis‰argumentit indeksist‰ 1-eteenp‰in

	cout << "Annoit " << argc << " argumenttia" << endl;
	cout << "Argumentit: " << endl;

	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;;
	}
	
	system("pause");
	return 0;
}