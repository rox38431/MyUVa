/*******************************************************/
/* UVa 305 - Joseph								       */
/* Author: rox38431									   */
/* Version: 2018/04/02                                 */
/*******************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	int ans[14];
	for (int k = 1; k <= 13; k++) {
		int m = 2, temp_k;
		int now_kill = -1, killed = 0;

		while (killed != k) {
			killed = 0;
			now_kill = -1;
			temp_k = k * 2;

			for (int j = 0; j < k; j++) {
				now_kill = (now_kill + m) % temp_k;
				if (now_kill < k) {
					m++;
					break;
				}
				else {
					now_kill--;
					killed++;
					temp_k--;
				}
			}
		}
		ans[k] = m;
	}

	int k;
	while (cin >> k && k != 0) {
		cout << ans[k] << endl;
	}

	return 0;
}