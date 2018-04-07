/*******************************************************/
/* UVa 543 - Goldbach's Conjecture				       */
/* Author: rox38431									   */
/* Version: 2018/04/07                                 */
/*******************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	static bool prime[1000001];
	for (int i = 0; i < 1000001; i++)
		prime[i] = true;
	for (int i = 2; i < 1000001 / 2; i++) {
		if (prime[i]) {
			for (int j = i + i; j < 1000001; j += i) {
				prime[j] = false;
			}
		}
	}


	int num;
	while (cin >> num && num != 0) {
		int found = 0;
		for (int i = 3; i <= num / 2; i++) {
			if (prime[i] && prime[num - i]) {
				cout << num << " = " << i << " + " << num - i << endl;
				found = 1;
				break;
			}
		}
		if (found == 0)
			cout << "Goldbach's conjecture is wrong." << endl;
	}

	return 0;
} 
