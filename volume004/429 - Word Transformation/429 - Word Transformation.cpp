/*******************************************************/
/* UVa 429 - Word Transformation			           */
/* Author: rox38431									   */
/* Version: 2018/04/03                                 */
/*******************************************************/

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

#define min(a, b) ((a < b) ? a : b);

using namespace std;

int main() {
	string s;
	int cases;
	getline(cin, s);
	istringstream stream(s);
	stream >> cases;


	for (int round = 0; round < cases; round++) {
		map<string, int> word_hash;
		string words[200];
		int count = 0;

		if (round == 0)
			getline(cin, s);	// just get blank line
		else
			cout << endl;

		while (getline(cin, s)) {
			if (s == "*")
				break;
			if (word_hash.find(s) == word_hash.end()) {
				word_hash[s] = count;
				words[count] = s;
				count++;
			}
		}

		int **transform = new int *[count];
		for (int i = 0; i < count; i++)
			transform[i] = new int[count];
		
		for (int i = 0; i < count; i++) {
			transform[i][i] = 0;
			for (int j = i + 1; j < count; j++) {
				if (words[i].length() != words[j].length()) {
					transform[i][j] = 1000;
					transform[j][i] = 1000;
				}
				else {
					int diff_count = 0;
					for (int k = 0; k < words[i].length() && diff_count <= 2; k++) {
						if (words[i][k] != words[j][k])
							diff_count++;
					}

					if (diff_count <= 1) {
						transform[i][j] = 1;
						transform[j][i] = 1;
					}
					else {
						transform[i][j] = 1000;
						transform[j][i] = 1000;
					}
				}
			}
		}

		for (int k = 0; k < count; k++) {
			for (int i = 0; i < count; i++) {
				for (int j = 0; j < count; j++) {
					transform[i][j] = min(transform[i][k] + transform[k][j], transform[i][j]);
				}
			}
		}

		while (getline(cin, s)) {
			if (s.length() == 0)
				break;
			istringstream istr(s);
			string start_word, end_word;
			int start_num, end_num;
			istr >> start_word >> end_word;
			start_num = word_hash[start_word];
			end_num = word_hash[end_word];
			cout << start_word << " " << end_word << " " << transform[start_num][end_num] << endl;
		}
		
	}

	return 0;
}
