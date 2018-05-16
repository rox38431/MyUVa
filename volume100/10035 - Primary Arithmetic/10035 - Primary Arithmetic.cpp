/*******************************************************/
/* UVa 10035 - Primary Arithmetic					   */
/* Author: rox38431									   */
/* Version: 2018/05/16                                 */
/*******************************************************/

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

#define max(a, b) ((a > b) ? a : b);

using namespace std;

void getInitNum(int num[100]) {
	for (int i = 0; i < 100; i++)
		num[i] = 0;
}

int main() {
	string input1, input2;
	int num1[100], num2[100];
	int len1, len2, max_len;
	int carry, carry_count;

	while (cin >> input1 >> input2 && (input1 != "0" || input2 != "0")) {
		carry_count = 0;
		getInitNum(num1);
		getInitNum(num2);

		for (int i = 0; i < input1.length(); i++)
			num1[i] = input1[input1.length() - 1 - i] - '0';

		for (int i = 0; i < input2.length(); i++)
			num2[i] = input2[input2.length() - 1 - i] - '0';

		max_len = max(input1.length(), input2.length());
		for (int i = 0; i <= max_len; i++) {
			num1[i] += num2[i];
			carry = floor(num1[i] / 10);
			if (carry > 0) {
				carry_count++;
				num1[i + 1] += carry;
			}
			num1[i] %= 10;
		}

		if (carry_count == 0)
			cout << "No carry operation." << endl;
		else if (carry_count == 1)
			cout << carry_count << " carry operation." << endl;
		else
			cout << carry_count << " carry operations." << endl;
	}

	return 0;
}
