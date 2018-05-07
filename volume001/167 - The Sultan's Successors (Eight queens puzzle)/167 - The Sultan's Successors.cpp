/*******************************************************/
/* UVa 167 - The Sultan's Successors	        	   */
/* Author: rox38431									   */
/* Version: 2018/05/07                                 */
/*******************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

static int queen_combination[100][8];
int move_record[10],  A[24],  B[24],  C[24];
int combine_count;

void lay(int i) {

	int right_up, right, right_down;
	for (int j = 1; j <= 8; j++) {
		right_down = j - i + 7;
		right = j;
		right_up = i + j;
		if (A[right_down] == 0 && B[j] == 0 && C[right_up] == 0) {
			A[right_down] = B[j] = C[right_up] = 1;
			move_record[i] = j;
			if (i == 8) {
				for (int k = 1; k <= 8; k++)
					queen_combination[combine_count][k] = move_record[k];
				combine_count++;
			}
			else {
				lay(i + 1);
			}
			A[right_down] = B[j] = C[right_up] = 0;
			move_record[i] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 24; i++)
		A[i] = B[i] = C[i] = 0;
	for (int i = 0; i < 10; i++)
		move_record[i] = 0;

	combine_count = 0;
	lay(1);

	int cases;
	int board[9][9];
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		int max = 0, temp_sum;
		for (int j = 1; j <= 8; j++) {
			for (int k = 1; k <= 8; k++) {
				cin >> board[j][k];
			}
		}

		for (int move = 0; move < combine_count; move++) {
			temp_sum = 0;
			for (int round = 1; round <= 8; round++) {
				temp_sum = temp_sum + board[round][queen_combination[move][round]];
			}
			if (temp_sum > max)
				max = temp_sum;
		}
		cout << setw(5) << max << endl;
	}
	
	return 0;
}