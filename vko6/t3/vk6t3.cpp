#include <iostream>

using namespace std;

int calculateDigits(char*);

int main()
{
	char* lause = "Onpa hieno lause";

	cout << "Lauseen pituus: " << calculateDigits(lause) << " merkkia" << endl;

	system("pause");
	return 0;
}

int calculateDigits(char *textPtr)
{
	int count = 0;

	while (*textPtr != '\0')
	{
		count++;
		textPtr++;
	}
	return count;
}
