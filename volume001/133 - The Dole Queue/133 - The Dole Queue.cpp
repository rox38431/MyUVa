/*******************************************************/
/* UVa 133 - The Dole Queue							   */
/* Author: rox38431									   */
/* Version: 2018/05/15                                 */
/*******************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
	int N, k, m;
	int applicants[20];
	while (cin >> N >> k >> m && (N != 0 || k != 0 || m != 0)) {
		for (int i = 0; i < N; i++)
			applicants[i] = i + 1;
		int num = N;
		int first = -1, second = N;

		while (num != 0) {
			for (int i = 1; i <= k; i++) {
				first = (first + 1) % N;
				if (applicants[first] == -1)
					i--;
			}
			for (int i = 1; i <= m; i++) {
				second = (second - 1 + N) % N;
				if (applicants[second] == -1)
					i--;
			}

			cout << setw(3) << applicants[first];
			if (first != second) {
				cout << setw(3) << applicants[second];
				num--;
			}
			num--;
			applicants[first] = applicants[second] = -1;

			if (num != 0)
				cout << ",";
			else
				cout << endl;
		}
	}
	return 0;
}