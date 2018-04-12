/*******************************************************/
/* UVa 113 - Power of Cryptography			  		   */
/* Author: rox38431									   */
/* Version: 2018/04/12                                 */
/*******************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
	double n, p;

	while (cin >> n >> p) {
		cout << fixed << setprecision(0) << pow(p, 1 / n) << endl;
	}

	return 0;
}