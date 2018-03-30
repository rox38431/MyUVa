/*******************************************************/
/* UVa 156 - Ananagrams              			       */
/* Author: rox38431									   */		
/* Version: 2018/03/30                                 */
/*******************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;

string toLower(string);
void str_bubble_sort(string *, int);

int main() {
	map<string, int> mapWord;
	map<string, int>::iterator iter;

	string input_line;
	string original_word[10000];
	int word_count[10000];
	int count = 0;
	string word;

	while (cin >> word) {
		if (word == "#")
			break;

		original_word[count] = word;
		word = toLower(word);
		sort(word.begin(), word.end());

		iter = mapWord.find(word);
		if (iter != mapWord.end()) {
			word_count[iter->second]++;
		}
		else {
			word_count[count] = 1;
			mapWord[word] = count;
			count++;
		}
	}

	int ans_count = 0;
	string *ans_word = new string[10000];
	for (int i = 0; i < count; i++) {
		if (word_count[i] == 1) {
			ans_word[ans_count] = original_word[i];
			ans_count++;
		}
	}

	str_bubble_sort(ans_word, ans_count);

	for (int i = 0; i < ans_count; i++)
		cout << ans_word[i] << endl;

	return 0;
}

string toLower(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] < 97)
			s[i] += 32;
	}

	return s;
}

void str_bubble_sort(string *word, int size) {
	for (int i = 1; i <= size - 1; i++) {
		for (int j = 0; j < size - i; j++) {
			if (word[j] > word[j + 1])
				swap(word[j], word[j + 1]);
		}
	}
}
