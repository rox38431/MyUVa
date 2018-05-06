/*******************************************************/
/* UVa 147 - Dollars								   */
/* Author: rox38431									   */
/* Version: 2018/05/06                                 */
/*******************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
	double input;
	int dollars[11] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
	static double dp[30001][11];

	for (int i = 0; i < 11; i++)
		dp[0][i] = 1;

	for (int i = 5; i <= 30000; i += 5) {
		dp[i][0] = dp[i - dollars[0]][0];
		for (int j = 1; j < 11; j++) {
			if (dollars[j] > i)
				dp[i][j] = dp[i][j - 1];
			else
				dp[i][j] = dp[i][j - 1] + dp[i - dollars[j]][j];
		}
	}

	while (cin >> input && input != 0) {
		double temp_input = input * 100;
		int index = (int)round(temp_input);
		cout << fixed << setw(6) << setprecision(2) << input;
		cout << setw(17) << setprecision(0) << dp[index][10] << endl;
	}

	return 0;
}

