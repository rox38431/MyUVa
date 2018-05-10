/*******************************************************/
/* UVa - 13216 Problem with a ridiculously long name   */
/*       but with a ridiculously short description	   */
/* Author: rox38431									   */
/* Version: 2018/05/10                                 */
/*******************************************************/

//66
//56, 96, 36, 76, 16
//56, 96, 36, 76, 16
//...

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	int cases;
	string n;
	int remainder[5] = {76, 16, 56, 96, 36};
	cin >> cases;

	for (int i = 0; i < cases; i++) {
		cin >> n;
		int last_digit = n[n.length() - 1] - 48;

		if (n.length() == 1 && last_digit == 1)
			cout << 66 << endl;
		else if (n.length() == 1 && last_digit == 0)
			cout << 1 << endl;
		else
			cout << remainder[last_digit % 5] << endl;
	}

	return 0;
}