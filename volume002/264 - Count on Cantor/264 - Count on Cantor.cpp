/*******************************************************/
/* UVa 264 - Count on Cantor		 				   */
/* Author: rox38431									   */
/* Version: 2018/04/13                                 */
/*******************************************************/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int input;
	while (cin >> input) {
		int level = 0;
		int total_num = 0;
		int dir = 0;

		while (input > total_num + level + 1) {
			level++;
			total_num = total_num + level;
			dir = (dir + 1) % 2;
		}

		cout << "TERM " << input << " IS ";
		if (dir == 0)
			cout << level + 2 - (input - total_num) << "/" << input - total_num << endl;
		else
			cout << input - total_num << "/" << level + 2 - (input - total_num) << endl;
	}

	return 0;
}