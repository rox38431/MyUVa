#include <iostream>
#include <string>
using namespace std;

int main()	{
	string sInput;

	int iQuoteCount = 0;		// �Y�����ƫh���Ĥ@�� quote�A�_�h���ĤG��

	while (getline(cin, sInput))	{
		for (int i = 0; i < sInput.length(); i++)	{
			if (sInput[i] == '\"')	{		// �T�{���Ĥ@�� quotes
				if (iQuoteCount % 2 == 0)
					cout << "``";
				else						// �T�{���ĤG�� quotes 
					cout << "\'\'";

				++iQuoteCount;
			}
			else
				cout << sInput[i];
		}
		cout << endl;
	}

	return 0;
}