/*******************************************************/
/* UVa 541 - Error Correction				           */
/* Author: rox38431									   */
/* Version: 2018/04/07                                 */
/*******************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int dimensions;
	int matrix[100][100];

	while (cin >> dimensions && dimensions != 0) {
		for (int i = 1; i <= dimensions; i++)	{
			for (int j = 1; j <= dimensions; j++) {
				cin >> matrix[i][j];
			}
		}

		int row_odd = -1;
		int col_odd = -1;

		for (int i = 1; i <= dimensions; i++) {
			int temp_row_sum = 0;
			int temp_col_sum = 0;

			for (int j = 1; j <= dimensions; j++) {
				temp_row_sum = temp_row_sum + matrix[i][j];
				temp_col_sum = temp_col_sum + matrix[j][i];
			}

			if (temp_row_sum % 2 == 1 && row_odd == -1) {
				row_odd = i;
			}
			else if (temp_row_sum % 2 == 1 && row_odd != -1) {
				row_odd = -2;
				break;
			}

			if (temp_col_sum % 2 == 1 && col_odd == -1) {
				col_odd = i;
			}
			else if (temp_col_sum % 2 == 1 && col_odd != -1) {
				col_odd = -2;
				break;
			}
		}

		if (row_odd == -1 && col_odd == -1)
			cout << "OK" << endl;
		else if (row_odd == -2 || col_odd == -2)
			cout << "Corrupt" << endl;
		else
			cout << "Change bit (" << row_odd << "," << col_odd << ")" << endl;
	}

	return 0;
} 