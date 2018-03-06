/*******************************************************/
/* UVa 103 Stacking Boxes                              */
/* Author: rox38431									   */		
/* Version: 2018/02/25                                 */
/*******************************************************/

#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

int **create_2d_array(int, int);
void sort_dimension(int *, int);
void sort_box(int **, int, int, int*);
bool isContain(int *, int *, int);
bool box_compare(int *, int *, int);

int main() {
	int box_num, box_dimension;
	int **box = NULL;
	while (cin >> box_num >> box_dimension) {
		box = create_2d_array(box_num, box_dimension);


		for (int i = 0; i < box_num; i++) {
			sort_dimension(box[i], box_dimension);
		}


		int *sorted_sequence = new int[box_num];
		for (int i = 0; i < box_num; i++) {
			sorted_sequence[i] = i + 1;
		}

		sort_box(box, box_num, box_dimension, sorted_sequence);


		int *length = new int[box_num];
		int *pre_box = new int[box_num];

		for (int i = 0; i < box_num; i++){
			length[i] = 1;
			pre_box[i] = -1;
		}

		for (int i = 0; i < box_num; i++) {
			for (int j = i + 1; j < box_num; j++) {
				if (isContain(box[j], box[i], box_dimension)) {
					if (length[i] + 1 > length[j])	{
						length[j] = length[i] + 1;
						pre_box[j] = i;
					}
				}
			}
		}

		int max_length = 1;
		int last_box = -1;
		for (int i = 0; i < box_num; i++) {
			if (max_length < length[i]) {
				max_length = length[i];
				last_box = i;
			}
		}
	
		int *lis = new int[max_length];
		int box_count = max_length - 1;
		while (last_box != -1) {
			lis[box_count] = last_box;
			last_box = pre_box[last_box];
			box_count--;
		}

		cout << max_length << endl;
		for (int i = 0; i < max_length; i++)
			cout << sorted_sequence[lis[i]] << " ";
		cout << endl;
	}

	//system("pause");
	return 0;
}

int **create_2d_array(int row, int col) {

	int **box_info = new int*[row];
	for (int i = 0; i < row; i++) {
		box_info[i] = new int[col];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> box_info[i][j];
		}
	}
	
	return box_info;
}

void sort_dimension(int *box, int dimensions) {
	for (int i = 1; i < dimensions; i++) {
		int j = i - 1;
		int key = box[i];
		while (j >= 0 && box[j] > key)	{
			box[j + 1] = box[j];
			j--;
		}
		box[j + 1] = key;
	}
}

void sort_box(int **box_list, int box_num, int dimensions, int *sequence) {
	// insertion sort
	for (int i = 1; i < box_num; i++) {
		int j = i - 1;
		int *temp_box_ptr = box_list[i];
		int temp_num = i + 1;
		while (j >= 0 && box_compare(box_list[j], temp_box_ptr, dimensions)) {
			box_list[j + 1] = box_list[j];
			sequence[j + 1] = sequence[j];
			j--;
		}
		box_list[j + 1] = temp_box_ptr;
		sequence[j + 1] = temp_num;

	}
}

bool box_compare(int *box_a, int *box_b, int box_dimensions) {
	for (int i = 0; i < box_dimensions; i++) {
		if (box_a[i] > box_b[i])
			return true;
		else if (box_a[i] < box_b[i])
			return false;
	}
	return false;
}


// test is box_a can contain box_b, if yes than return true, else return false
bool isContain(int* box_a, int *box_b, int dimensions) {
	for (int i = 0; i < dimensions; i++) {
		if (box_a[i] <= box_b[i])
			return false;
	}

	return true;
}