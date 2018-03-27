#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string all_to_lower_case(string);
string convert_mark_to_space(string);

int main()     {
	int total_key, total_excuses, count = 1;
	string keyword[20], excuses[20];

	while (cin >> total_key >> total_excuses)   {
		int max = -1, keyword_num[20] = { 0 };
		string temp;

		for (int i = 0; i < total_key; i++)
			cin >> keyword[i];


		getline(cin, excuses[0]);
		for (int i = 0; i < total_excuses; i++)
			getline(cin, excuses[i]);


		for (int k = 0; k < total_excuses; k++)     {

			temp = excuses[k];

			temp = all_to_lower_case(temp);
			temp = convert_mark_to_space(temp);

			istringstream input(temp);
			string term;

			while (input >> term)   {
				for (int i = 0; i < total_key; i++)     {
					if (term == keyword[i])
						keyword_num[k]++;
				}
			}

			if (max < keyword_num[k])
				max = keyword_num[k];
		}

		cout << "Excuse Set #" << count++ << endl;

		for (int i = 0; i < total_excuses; i++)     {
			if (max == keyword_num[i])
				cout << excuses[i] << endl;
		}

		cout << endl;
	}

	return 0;
}

string  all_to_lower_case(string sentence)     {

	for (int i = 0; i < sentence.length(); i++)
	if (sentence[i] >= 65 && sentence[i] <= 90)
		sentence[i] += 32;

	return sentence;

}

string convert_mark_to_space(string sentence)   {

	for (int i = 0; i < sentence.length(); i++)
	if (sentence[i] < 97 || sentence[i] > 122)
		sentence[i] = ' ';

	return sentence;

}

