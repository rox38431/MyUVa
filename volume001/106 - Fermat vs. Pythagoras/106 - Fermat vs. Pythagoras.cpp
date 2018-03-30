/*******************************************************/
/* UVa 106 - Fermat vs. Pythagoras                     */
/* Author: rox38431									   */		
/* Version: 2018/03/30                                 */
/*******************************************************/

#include <iostream>

using namespace std;

bool Coprime(int, int);


int main () {
	int z;
	static int num[1000001];

	while (cin >> z) {

		for (int i = 0; i <= z; i++) {
			num[i] = 0;
		}

		int prime_triple_count = 0;

		for (int x = 1; x <= 1000; x++) {
			for (int y = x + 1; y <= 1000; y += 2) {
				if (Coprime(y, x) == true) {

					int a = y * y - x * x;
					int b = 2 * x * y;
					int c = y * y + x * x;

					if (c > z)
						break;
					else {
						prime_triple_count++;

						int temp_a = a, temp_b = b, temp_c = c;
						while (temp_a <= z && temp_b <= z && temp_c <= z) {
							if (temp_a <= z) num[temp_a] = 1;
							if (temp_b <= z) num[temp_b] = 1;
							if (temp_c <= z) num[temp_c] = 1;

							temp_a += a;
							temp_b += b;
							temp_c += c;

						}
					}

				}
			}
		}

		int not_in = 0;
		for (int i = 1; i <= z; i++) {
			if (num[i] == 0) {
				not_in++;
			}

		}

		cout << prime_triple_count << " " << not_in << endl;

	}

	return 0;
}

bool Coprime(int a, int b) {
	int c = a % b;

	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}

	return ((b == 1) ? true : false);
}