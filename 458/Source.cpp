#include <iostream>
#include <string>

using namespace std;

int main()	{
	string sInput;

	while (getline(cin, sInput)) {
		for (int i = 0; i < sInput.length(); i++) {
			int iAscii = sInput[i] - 7;
			cout << (char)iAscii;
		}
		cout << endl;
	}

	//system("pause");
	return 0;

}