/*******************************************************/
/* UVa 175 - Keywords	        					   */
/* Author: rox38431									   */
/* Version: 2018/05/08                                 */
/*******************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	int profile_count = 0, title_count = 0;
	int word_count;
	string input;
	int now_state;	// 1 for profile, 2 for title
	int distance[51], title_word_count[51];
	string word[51][250];
	vector<map<string, int>> vec_of_maps;
	map<string, int> keyword_map;
	map<string, int>::iterator iter;

	vec_of_maps.push_back(keyword_map);	// 無意義，占掉 vector 位置 0 而已

	while (cin >> input && input != "#") {
		if (input == "P:") {
			if (profile_count != 0)
				vec_of_maps.push_back(keyword_map);
			keyword_map.clear();
			now_state = 1;
			profile_count++;
			cin >> distance[profile_count];
		}
		else if (input == "T:") {
			if (title_count == 0)
				vec_of_maps.push_back(keyword_map);
			word_count = 0;
			now_state = 2;
			title_count++;
		}
		else {
			string temp = "";
			for (int i = 0; i < input.length(); i++) {
				if (input[i] >= 'A' && input[i] <= 'Z')
					temp += (input[i] + 32);
				else if (input[i] >= 'a' && input[i] <= 'z') 
					temp += input[i];
			}

			if (now_state == 1) {
				if (temp.length() != 0) {
					if (keyword_map.find(temp) == keyword_map.end())
						keyword_map[temp] = 1;
					else
						keyword_map[temp] = 2;
				}
			}
			else if (now_state == 2) {
				if (temp.length() != 0) {
					word[title_count][word_count] = temp;
					word_count++;
					title_word_count[title_count] = word_count;
				}
			}
		}
	}

	for (int i = 1; i <= profile_count; i++) {
		cout << i << ": ";
		bool first = true, find = false;
		for (int j = 1; j <= title_count; j++) {
			for (int k = 0; k < title_word_count[j]; k++) {
				if (vec_of_maps[i].find(word[j][k]) != vec_of_maps[i].end()) {	 // 確認句子中第 k 個字是否在第 i 個 profile 中
					for (int range = k + 1; (range <= k + 1 + distance[i]) && range < title_word_count[j]; range++) { // 檢查句子中第 k+1 到 k+1+between 個字
						if (vec_of_maps[i].find(word[j][range]) != vec_of_maps[i].end()) {		// 若檢查到的字在 profile i 中
							if (vec_of_maps[i][word[j][range]] == 2 || word[j][k] != word[j][range]) {	// 檢查目前的兩個字是否相同，或 profile i 中有重複出現
								if (first) {
									cout << j;
									first = false;
								}
								else
									cout << "," << j;
							}
						}
					}
				}
			}
		}
		cout << endl;
	}

	return 0;
}
