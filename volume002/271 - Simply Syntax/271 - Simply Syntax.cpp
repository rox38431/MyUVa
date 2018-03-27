/*******************************************************/
/* UVa 271 Simply Syntax                               */
/* Author: rox38431									   */		
/* Version: 2018/03/27                                 */
/*******************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
	string input_line;

	while (getline(cin, input_line)) {
		int top = -1;
		int len = input_line.length();

		for (int i = len - 1; i >= 0; i--) {
			if (input_line[i] >= 'p' && input_line[i] <= 'z') {
				top++;
			}
			else if (input_line[i] == 'N') {
				if (top == -1) {
					cout << "NO" << endl;
					break;
				}
			}
			else if (input_line[i] == 'C' || input_line[i] == 'D' || input_line[i] == 'E' || input_line[i] == 'I') {
				if (top < 1) {
					cout << "NO" << endl;
					break;
				}
				else
					top--;
			}
			else {
				cout << "NO" << endl;
				break;
			}

			if (i == 0) {
				if (top == 0)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
		}
	}

	return 0;
}