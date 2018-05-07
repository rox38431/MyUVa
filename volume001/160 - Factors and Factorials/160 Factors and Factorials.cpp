/*******************************************************/
/* UVa 160 Factors and Factorials                      */
/* Author: rox38431									   */
/* Version: 2018/04/01                                 */
/*******************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int prime[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 
		              47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
	int factor[101][25];
	int ans[101][25];

	// initialize array to 0
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 25; j++) {
			factor[i][j] = 0;
			ans[i][j] = 0;
		}
	}

	// 計算 2 到 100 中所有數的質因數分解
	for (int i = 2; i <= 100; i++) {
		int num = i;

		int k = 0;
		while (k < 25 && num != 1) {
			if (num % prime[k] == 0) {
				factor[i][k]++;
				num = num / prime[k];
			}
			else
				k++;
		}
	}

	// 計算 i! 的質因數分解，其中 2 <= i <= 100
	for (int i = 2; i <= 100; i++)
		for (int j = 0; j < 25; j++)
			ans[i][j] = ans[i - 1][j] + factor[i][j];

	// 輸出 ans
	int input_num;
	while (cin >> input_num && input_num != 0) {
		int count = 0;
		cout << setw(3) << input_num;
		cout << "! =";
		for (int i = 0; i < 25; i++) {
			if (ans[input_num][i] == 0)
				break;
			else {
				if (count == 15)
					cout << endl << "      ";
				cout << setw(3) << ans[input_num][i];
				count++;
			}
		}
		cout << endl;
	}

	return 0;
}