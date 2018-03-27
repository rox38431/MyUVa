#include <iostream>
#include <string>
using namespace std;

int main()	{
	string sInput;

	int iQuoteCount = 0;		// 若為偶數則為第一個 quote，否則為第二個

	while (getline(cin, sInput))	{
		for (int i = 0; i < sInput.length(); i++)	{
			if (sInput[i] == '\"')	{		// 確認為第一個 quotes
				if (iQuoteCount % 2 == 0)
					cout << "``";
				else						// 確認為第二個 quotes 
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