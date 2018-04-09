/*******************************************************/
/* UVa 111 - History Grading			    	       */
/* Author: rox38431									   */
/* Version: 2018/04/09                                 */
/*******************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

#define max(a, b) ((a > b) ? a : b);

int main() {
	int size;
	string s;
	int correct[21];
	int stu_ans[21];
	int matrix[21][21];
	int temp;

	cin >> size;
	for (int i = 1; i <= size; i++) {
		cin >> temp;
		correct[temp] = i;
	}

	getline(cin, s);
	while (getline(cin, s)) {
		istringstream stream(s);

		for(int i = 1; i <= size; i++) {
			stream >> temp;
			stu_ans[temp] = i;
		}

		for (int i = 0; i <= size; i++)
			matrix[0][i] = 0;

		for (int i = 1; i <= size; i++) {
			matrix[i][0] = 0;
			for (int j = 1; j <= size; j++) {
				if (correct[j] == stu_ans[i])
					matrix[i][j] = matrix[i - 1][j - 1] + 1;
				else
					matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
			}
		}
		cout << matrix[size][size] << endl;
	}

	return 0;
}