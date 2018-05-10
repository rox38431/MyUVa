/*******************************************************/
/* UVa 154 - Recycling								   */
/* Author: rox38431									   */
/* Version: 2018/05/10                                 */
/*******************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

string replace_char(string input) {
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == 'r' || input[i] == 'P')
			input[i] = '0';
		else if (input[i] == 'o' || input[i] == 'G')
			input[i] = '1';
		else if (input[i] == 'y' || input[i] == 'A')
			input[i] = '2';
		else if (input[i] == 'g' || input[i] == 'S')
			input[i] = '3';
		else if (input[i] == 'b' || input[i] == 'N')
			input[i] = '4';
		else
			input[i] = ' ';
	}
	return input;
}

int main() {
	string input;
	int count = 0;
	static int city_alloc[100][5];
	static int city_diff[100][100];

	while (getline(cin, input)) {
		if (input == "#")
			break;
		else if (input[0] == 'e') {

			for (int i = 0; i < count; i++) {
				for (int j = i; j < count; j++) {
					city_diff[i][j] = city_diff[j][i] = 0;
					for (int k = 0; k < 5; k++) {
						if (city_alloc[i][k] != city_alloc[j][k]) {
							city_diff[i][j]++;
							city_diff[j][i] = city_diff[i][j];
						}
					}
				}
			}

			int min = 0, choose_city = 0, temp_min = 0;
			for (int i = 0; i < count; i++)
				min += city_diff[0][i];

			for (int i = 1; i < count; i++) {
				temp_min = 0;
				for (int j = 0; j < count; j++)
					temp_min += city_diff[i][j];
				if (temp_min < min) {
					min = temp_min;
					choose_city = i;
				}
			}

			cout << choose_city + 1 << endl;
			count = 0;
		}
		else {
			input = replace_char(input);
			istringstream stream(input);
			int index, num;
			for (int i = 0; i < 5; i++) {
				stream >> index >> num;
				city_alloc[count][index] = num;

			}
			count++;
		}
	}

	return 0;
}
