/*******************************************************/
/* UVa 119 - Greedy Gift Givers						   */
/* Author: rox38431									   */
/* Version: 2018/05/03                                 */
/*******************************************************/

#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

int main() {
	int person;
	string name[10];
	int gain[10];
	bool first = true;

	while (cin >> person) {
		if (first)
			first = false;
		else
			cout << endl;

		map<string, int> person_map;
		map<string, int>::iterator iter;

		for (int i = 0; i < person; i++) {
			cin >> name[i];
			person_map[name[i]] = i;
			gain[i] = 0;
		}

		for (int i = 0; i < person; i++) {
			string from_name, to_name;
			int money, to_num;
			int from_index, to_index, give_money, loss_money;
			cin >> from_name >> money >> to_num;

			iter = person_map.find(from_name);
			from_index = iter->second;

			if (to_num == 0)
				give_money == 0;
			else 
				give_money = money / to_num;
			
			loss_money = give_money * to_num;
			gain[from_index] -= loss_money;

			for (int j = 0; j < to_num; j++) {
				cin >> to_name;
				iter = person_map.find(to_name);
				to_index = iter->second;
				gain[to_index] += give_money;
			}
		}

		for (int i = 0; i < person; i++) {
			cout << name[i] << " " << gain[i] << endl;
		}
	}

	return 0;
}