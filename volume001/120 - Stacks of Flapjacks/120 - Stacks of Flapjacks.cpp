/*******************************************************/
/* 120 - Stacks of Flapjacks		 				   */
/* Author: rox38431									   */
/* Version: 2018/05/01                                 */
/*******************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void flip(int arr[30], int start, int end) {
	for (int i = 0; i < (end - start + 1) / 2; i++)
		swap(arr[start + i], arr[end - i]);
}

int main() {
	int diameter[30];
	string s;

	while (getline(cin, s)) {
		int count = 0;
		istringstream stream(s);
		while (stream) {
			stream >> diameter[count];
			count++;
		}
		count--;

		for (int i = 0; i < count / 2; i++) {
			swap(diameter[i], diameter[count - 1 - i]);
		}

		cout << s << endl;

		int max, max_pos;
		for (int i = 0; i < count; i++) {
			max = diameter[i];
			max_pos = i;
			for (int j = i + 1; j < count; j++) {
				if (max < diameter[j]) {
					max = diameter[j];
					max_pos = j;
				}
			}

			if (max_pos != i) {
				if (max_pos != count - 1) {
					cout << max_pos + 1 << " ";
					flip(diameter, max_pos, count - 1);
				}
				cout << i + 1 << " ";
				flip(diameter, i, count - 1);
			}
		}
		cout << 0 << endl;
	}
}