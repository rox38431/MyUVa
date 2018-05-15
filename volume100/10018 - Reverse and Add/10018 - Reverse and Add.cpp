/*******************************************************/
/* UVa 10018 - Reverse and Add						   */
/* Author: rox38431									   */
/* Version: 2018/05/15                                 */
/*******************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

bool isPalindrome(int num[11], int len) {
	for (int i = 0; i < len / 2; i++) {
		if (num[i] != num[len - 1 - i])
			return false;
	}
	return true;
}

void getAddReverse(int num[11], int &len) {
	int temp[11];
	for (int i = 0; i < 11; i++)
		temp[i] = num[i];

	for (int i = 0; i < len; i++) {
		num[i] = num[i] + temp[len - 1 - i];
		num[i + 1] = num[i + 1] + floor(num[i] / 10);
		num[i] = num[i] % 10;
	}

	if (num[len] != 0)
		len++;
}

int main() {
	int cases;
	int num[11];
	string input;
	cin >> cases;

	while (cases--) {
		cin >> input;

		for (int i = 0; i < 11; i++)
			num[i] = 0;

		int iter = 0, len = input.length();
		for (int i = input.length() - 1, j = 0; i >= 0; i--, j++)
			num[j] = input[i] - '0';

		iter = 1;
		getAddReverse(num, len);

		while (isPalindrome(num, len) == false) {
			iter++;
			getAddReverse(num, len);
		}
		cout << iter << " ";
		for (int i = 0; i < len; i++)
			cout << num[len - 1 - i];
		cout << endl;
	}

	return 0;
}