/*******************************************************/
/* UVa 401 - Palindromes							   */
/* Author: rox38431									   */
/* Version: 2018/04/02                                 */
/*******************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	bool mirror = true;
	bool palindrome = true;
	string input;
	char reverse[91];
	
	for (int i = 0; i < 91; i++)
		reverse[i] = '-';

	reverse[65] = 'A';  reverse[69] = '3';  reverse[72] = 'H';
	reverse[73] = 'I';  reverse[74] = 'L';  reverse[76] = 'J';
	reverse[77] = 'M';  reverse[79] = 'O';  reverse[83] = '2';
	reverse[84] = 'T';  reverse[85] = 'U';  reverse[86] = 'V';
	reverse[87] = 'W';  reverse[88] = 'X';  reverse[89] = 'Y';
	reverse[90] = '5';  reverse[49] = '1';  reverse[50] = 'S';
	reverse[51] = 'E';  reverse[53] = 'Z';  reverse[56] = '8';

	while (getline(cin, input)) {
		int len = ((input.length() % 2 == 0) ? input.length() / 2 : input.length() / 2 + 1);
		int start = 0, end = input.length() - 1;
		mirror = true;
		palindrome = true;

		for (int i = 0; i < len; i++) {
			if (input[start] != input[end])
				palindrome = false;
			if (reverse[input[start]] == '-' || reverse[input[end]] == '-' || reverse[input[start]] != input[end])
				mirror = false;

			start++;
			end--;
		}

		if (mirror == false && palindrome == false)
			cout << input << " -- is not a palindrome." << endl;
		else if (mirror == false && palindrome == true)
			cout << input << " -- is a regular palindrome." << endl;
		else if (mirror == true && palindrome == false)
			cout << input << " -- is a mirrored string." << endl;
		else	
			cout << input << " -- is a mirrored palindrome." << endl;
		cout << endl;

	}

	return 0;
}

