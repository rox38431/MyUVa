/*******************************************************/
/* UVa 107 - The Cat in the Hat                        */
/* Author: rox38431									   */		
/* Version: 2018/03/29                                 */
/*******************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main () {
	int H, W;
	while (cin >> H >> W) {
		if (H == 0 && W == 0)
			break;
		else if (H == 1 && W == 1) {
			cout << "0 1" << endl;
			continue;
		}

		int N = 1;
		while (true) {
			if (abs((log10(N + 1) * log10(W)) - (log10(H) * log10(N))) < 0.00000000000001) {
				break;
			}
			N++;
		}

		int sum_height = H, temp_H = H, not_work = 1, pow_N = 1;

		while (temp_H != 1) {
			temp_H = temp_H / (N + 1);
			pow_N = pow_N * N;
			sum_height = sum_height + temp_H * pow_N;

			if (temp_H != 1) {
				not_work = not_work + pow_N;
			} 
		}

		cout << not_work << " " << sum_height << endl;

	}

	return 0;
}