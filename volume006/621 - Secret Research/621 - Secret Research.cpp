/*******************************************************/
/* UVa 621 - Secret Research					       */
/* Author: rox38431									   */
/* Version: 2018/04/07                                 */
/*******************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	int size;
	string input;

	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> input;
		if (input == "1" || input == "4" || input == "78")
			cout << "+" << endl;
		else if (input[input.length() - 2] == '3' && input[input.length() - 1] == '5')
			cout << "-" << endl;
		else if (input[0] == '9' && input[input.length() - 1] == '4')
			cout << "*" << endl;
		else
			cout << "?" << endl;
	}

	return 0;
}
