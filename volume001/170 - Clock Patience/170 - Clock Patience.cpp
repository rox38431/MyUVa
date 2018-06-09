/*******************************************************/
/* UVa 170 - Clock Patience							   */
/* Author: rox38431									   */
/* Version: 2018/06/09                                 */
/*******************************************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int getCardNum(string input_card) {
	int card_num;

	if (input_card[0] == 'A')
		return 1;
	else if (input_card[0] == 'T')
		card_num = 10;
	else if (input_card[0] == 'J')
		card_num = 11;
	else if (input_card[0] == 'Q')
		card_num = 12;
	else if (input_card[0] == 'K')
		card_num = 13;
	else
		card_num = input_card[0] - '0';

	return card_num;
}

int getPilePos(int pile, bool is_exposed[14][4]) {
	for (int i = 0; i < 4; i++) {
		if (is_exposed[pile][i] == false)
			return i;
	}
	return -1;
}

int main() {
	string input_card;
	string pile_card[14][4];
	bool is_exposed[14][4];
	
	while (cin >> input_card && input_card != "#") {
		pile_card[13][0] = input_card;

		for (int i = 1; i <= 13; i++) {
			for (int j = 0; j < 4; j++)
				is_exposed[i][j] = false;
		}

		int pile_num = 12, pos_num = 0;
		for (int i = 0; i < 51; i++) {
			cin >> input_card;
			pile_card[pile_num][pos_num] = input_card;
			pile_num--;
			if (pile_num == 0) {
				pile_num = 13;
				pos_num++;
			}
		}

		int exposed_count = 1;
		string current_card = pile_card[13][0];
		is_exposed[13][0] = true;
		int next_pile = getCardNum(current_card);
		int next_pos = getPilePos(next_pile, is_exposed);
		while (next_pos != -1) {
			is_exposed[next_pile][next_pos] = true;
			current_card = pile_card[next_pile][next_pos];
			exposed_count++;
			next_pile = getCardNum(current_card);
			next_pos = getPilePos(next_pile, is_exposed);
		}
		
		cout << setfill('0') << setw(2) << setprecision(0) << fixed << exposed_count << ",";
		cout << current_card << endl;
	}

	return 0;
}
