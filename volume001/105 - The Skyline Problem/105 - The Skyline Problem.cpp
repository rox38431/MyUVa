/*******************************************************/
/* UVa 105 The Skyline Problem                         */
/* Author: rox38431									   */		
/* Version: 2018/03/26                                 */
/*******************************************************/

#include <iostream>

using namespace std;

int main() {
	int coordinate[10000];
	int left_coordinate, height_coordinate, right_coordinate;

	for (int i = 0; i < 10000; i++)
		coordinate[i] = 0;

	while (cin >> left_coordinate >> height_coordinate >> right_coordinate) {
		for (int i = left_coordinate; i < right_coordinate; i++)	{
			if (coordinate[i] < height_coordinate) {
				coordinate[i] = height_coordinate;
			}
		}
	}

	cout << 1 << " " << coordinate[1];
	for (int i = 2; i < 10000; i++) {
		if (coordinate[i] != coordinate[i - 1]) {
			cout << " " << i << " " << coordinate[i];
		}
	}
	cout << endl;

	return 0;
}