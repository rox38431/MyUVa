/*******************************************************/
/* UVa 369 - Combinations					           */
/* Author: rox38431									   */
/* Version: 2018/04/02                                 */
/*******************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	long long int num[101][101];
	
	for (int i = 1; i <= 100; i++) {
		num[i][i] = 1;
		num[i][1] = i;
	}

	for (int i = 2; i <= 100; i++) {
		for (int j = 2; j < i; j++) {
			num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
		}
	}

	int m, n;
	while (cin >> m >> n && m != 0 && n != 0)
		cout << m << " things taken " << n << " at a time is " << num[m][n] << " exactly.\n";

	return 0;
}

