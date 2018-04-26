/*******************************************************/
/* UVa 116 - Unidirectional TSP		 				   */
/* Author: rox38431									   */
/* Version: 2018/04/26                                 */
/*******************************************************/

#include <iostream>

using namespace std;

int main() {
	int matrix[10][100];
	int len[10][100];
	int row, col;

	while (cin >> row >> col) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> matrix[i][j];
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (j == col - 1)
					len[i][j] = matrix[i][j];
				else
					len[i][j] = 1000000;
			}
		}

		for (int i = col - 2; i >= 0; i--) {
			for (int j = 0; j < row; j++) {

				int up = (j + row - 1) % row;
				int mid = j;
				int down = (j + 1) % row;

				if (len[j][i] > len[up][i + 1] + matrix[j][i])
					len[j][i] = len[up][i + 1] + matrix[j][i];
				if (len[j][i] > len[mid][i + 1] + matrix[j][i])
					len[j][i] = len[mid][i + 1] + matrix[j][i];
				if (len[j][i] > len[down][i + 1] + matrix[j][i])
					len[j][i] = len[down][i + 1] + matrix[j][i];
			}
		}

		int min_len = len[0][0];
		int start = 0;
		for (int i = 1; i < row; i++) {
			if (min_len > len[i][0]) {
				min_len = len[i][0];
				start = i;
			}
		}

		int temp_min_len = min_len - matrix[start][0];
		cout << start + 1;
		for (int i = 1; i < col; i++) {
			int up = (start + row - 1) % row;
			int mid = start;
			int down = (start + 1) % row;

			if (up > mid)
				swap(up, mid);
			if (up > down)
				swap(up, down);
			if (mid > down)
				swap(mid, down);

			if (len[up][i] == temp_min_len) {
				cout << " " << up + 1;
				start = up;
			}
			else if (len[mid][i] == temp_min_len) {
				cout << " " << mid + 1;
				start = mid;
			}
			else if (len[down][i] == temp_min_len) {
				cout << " " << down + 1;
				start = down;
			}
			temp_min_len = temp_min_len - matrix[start][i];
		}
		cout << endl;
		cout << min_len << endl;
	}

	return 0;
}