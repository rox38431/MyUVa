/*******************************************************/
/* UVa 195 - Anagram		  						   */
/* Author: rox38431									   */
/* Version: 2018/04/13                                 */
/*******************************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string reorder(string);
void permutation(string, int, int);

int main() {
	int size;
	string word;

	cin >> size;

	for (int round = 0; round < size; round++) {
		cin >> word;
		word = reorder(word);
		permutation(word, 0, word.length() - 1);
	}

	return 0;
}

string reorder(string word) {
	int len = word.length();
	double *word_to_num = new double[len];

	for (int i = 0; i < len; i++) {
		if (word[i] <= 'Z')
			word_to_num[i] = word[i] + 31.5;
		else
			word_to_num[i] = word[i];
	}

	for (int i = 1; i <= word.length(); i++) {
		for (int j = 0; j < len - i; j++) {
			if (word_to_num[j] > word_to_num[j + 1]) {
				swap(word_to_num[j], word_to_num[j + 1]);
				swap(word[j], word[j + 1]);
			}
		}
	}

	return word;
}

void permutation(string word, int start, int end) {
	
	if (start == end) {
		cout << word << endl;
	}
	else {
		string temp_word = word;
		string pre_temp_word = "";
		for (int i = start; i <= end; i++) {
			temp_word[start] = word[i];
			for (int j = start + 1, k = start; j <= end; j++, k++) {
				if (k != i)
					temp_word[j] = word[k];
				else
					j--;
			}

			if (pre_temp_word != temp_word) {
				pre_temp_word = temp_word;
				permutation(temp_word, start + 1, end);
			}
		}
	}
}