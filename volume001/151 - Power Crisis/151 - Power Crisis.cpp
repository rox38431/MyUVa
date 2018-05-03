/*******************************************************/
/* UVa 151 - Power Crisis			 				   */
/* Author: rox38431									   */
/* Version: 2018/05/03                                 */
/*******************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int region;

	while (cin >> region && region != 0) {

		int count = 1, m = 1, temp_region = region;;
		int now = 1, target = 12;
		while (true) {
			now = (now - 1 + m) % (temp_region - 1);
			if (count == region - 1) {
				cout << m << endl;
				break;
			}
			else if (now != target) {
				count++;
				temp_region--;
				if (now < target)
					target--;
			}
			else {
				count = 1;
				m++;
				temp_region = region;
				target = 12;
				now = 1;
			}
		}
	}

	return 0;
}