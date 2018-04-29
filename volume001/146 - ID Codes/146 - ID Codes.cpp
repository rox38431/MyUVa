/*******************************************************/
/* UVa 146 - ID Codes				 				   */
/* Author: rox38431									   */
/* Version: 2018/04/29                                 */
/*******************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string sort(string, int);

int main() {
	string input_id;

	while (cin >> input_id && input_id != "#") {
		bool find = false;
		int min_upper;

		for (int i = input_id.length() - 2; i >= 0; i--) {
			min_upper = -1;
			for (int j = i + 1; j < input_id.length(); j++) {
				if (input_id[j] > input_id[i]) {
					find = true;
					if (min_upper == -1 || input_id[min_upper] > input_id[j])
						min_upper = j;
				}
			}
			if (find) {
				swap(input_id[i], input_id[min_upper]);
				input_id = sort(input_id, i + 1);
				break;
			}
		}

		if (find)
			cout << input_id << endl;
		else
			cout << "No Successor" << endl;
	}

	return 0;
}

string sort(string word, int start) {
	for (int i = 1; i < word.length() - start; i++) {
		for (int j = start; j < word.length() - i; j++) {
			if (word[j] > word[j + 1])
				swap(word[j], word[j + 1]);
		}
	}

	return word;
}
