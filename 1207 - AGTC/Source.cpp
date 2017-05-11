#include <iostream>
#include <string>

using namespace std;

int **create2DArray(int, int);
void delete2DArray(int **, int);
int find_min(int **, int, int);

int main() {
	int first_len, second_len;
	string first_text, second_text;
	while (cin >> first_len >> first_text >> second_len >> second_text) {

		int **cost = create2DArray(first_len + 1, second_len + 1);	// �Ω���� cost

		for (int i = 1; i <= first_len; i++) {
			for (int j = 1; j <= second_len; j++) {
				if (first_text[i - 1] == second_text[j - 1])	{	// �r��@�M�r��G��諸�r���ۦP
					cost[i][j] = find_min(cost, i, j);
					if (cost[i][j] > cost[i - 1][j - 1])
						cost[i][j] = cost[i - 1][j - 1];
				}
				else {											// �r��@�M�r��G��諸�r�����P
					cost[i][j] = find_min(cost, i, j);
				}
			}
		}

		cout << cost[first_len][second_len] << endl;

		delete2DArray(cost, first_len);
	}

	return 0;
}

// �ʺA�s�W 2D Array
int** create2DArray(int x, int y) {
	int **arr = new int*[x];

	for (int i = 0; i < x; i++) {
		arr[i] = new int[y];
	}

	

	// ����l�� cost matrix ����
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (i == 0)
				arr[i][j] = j;
			else if (j == 0)
				arr[i][j] = i;
			else
				arr[i][j] = 0;
		}
	}

	return arr;
}

// �R���ʺA�s�W�� 2D Array
void delete2DArray(int **arr, int size) {
	for (int i = 0; i <= size; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

// ��� change, delete, insert ���Ӱʧ@ cost �̤p
int find_min(int **cost, int x, int y) {
	int min = cost[x - 1][y - 1] + 1;	// change cost

	if (min > cost[x - 1][y] + 1)	// delete cost
		min = cost[x - 1][y] + 1;
	if (min > cost[x][y - 1] + 1)	// insert cost
		min = cost[x][y - 1] + 1;

	return min;
}