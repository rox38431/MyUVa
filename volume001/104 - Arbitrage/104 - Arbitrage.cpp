/*******************************************************/
/* UVa 104 Arbitrage                                   */
/* Author: rox38431									   */		
/* Version: 2018/03/21                                 */
/*******************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {

	int size;
	int start = 0;
	while (cin >> size) {

		if (start == 0)
			start++;
		else
			cout << endl;


		double matrix[21][21][21];
		int pre_matrix[21][21][21];

		// initialization
		for (int i = 1; i <= 20; i++) {
			for (int j = 1; j <= 20; j++) {
				for (int k = 1; k <= 20; k++) {
					matrix[i][j][k] = 0;
				}
			}
		}

		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= size; j++) {
				if (i == j)
					matrix[1][i][j] = 1;
				else
					cin >> matrix[1][i][j];

				pre_matrix[1][i][j] = i;
			}
		}

		int end_node = 0;
		int len = 0;
		bool out = false;
		int round = 2;

		while (round <= size) {

			// Floyd-Warshall algo
			for (int k = 1; k <= size; k++) {
				for (int i = 1; i <= size; i++) {
					for (int j = 1; j <= size; j++) {

						double temp = matrix[round - 1][i][k] * matrix[1][k][j];

						if (temp > matrix[round][i][j]) {
							matrix[round][i][j] = temp;
							pre_matrix[round][i][j] = k;
						}
					}

				}
			}

			for (int i = 1; i <= size; i++) {
				if (matrix[round][i][i] > 1.01) {
					out = true;
					len = round;
					end_node = i;
					break;
				}
			}

			if (out  == true)
				break;
			round++;
		}

		if (out == true) {
			int *ans = new int[len + 1];
			ans[len] = end_node;
			for (int i = len - 1; i >= 0; i--) {
				int pre_node = ans[i + 1];
				ans[i] = pre_matrix[i + 1][end_node][pre_node];
			}

			for (int i = 0; i < len + 1; i++) {
				if (i != 0)
					cout << " ";
				cout << ans[i];
			}
		}
		else
			cout << "no arbitrage sequence exists";

	}	// end of cin while
	cout << endl;

}