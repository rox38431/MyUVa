/*******************************************************/
/* UVa 108 - Maximum Sum                               */
/* Author: rox38431									   */		
/* Version: 2018/03/29                                 */
/*******************************************************/

#include <iostream>

using namespace std;

int main () {
	int size;

	while (cin >> size) {
		int matrix[101][101];
		int sum[101][101];

		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= size; j++) {
				cin >> matrix[i][j];
			}
		}

		for (int i = 0; i <= size; i++) {
			sum[0][i] = 0;
			sum[i][0] = 0;
		}

		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= size; j++) {
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i][j];
			}
		}

		int max = -1;
		for (int x_1 = 1; x_1 <= size; x_1++) {
			for (int y_1 = 1; y_1 <= size; y_1++) {
				for (int x_2 = x_1; x_2 <= size; x_2++) {
					for (int y_2 = y_1; y_2 <= size; y_2++) {

						int temp_max = sum[x_2][y_2] - sum[x_2][y_1 - 1] - sum[x_1 - 1][y_2] + sum[x_1 - 1][y_1 - 1];
						if (temp_max > max) {
							max = temp_max;
						}

					}
				}
			}
		}
		cout << max << endl;
	}

	return 0;
}