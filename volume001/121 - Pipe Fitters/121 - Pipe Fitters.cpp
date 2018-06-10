/*******************************************************/
/* UVa 121 - Pipe Fitters							   */
/* Author: rox38431									   */
/* Version: 2018/06/10                                 */
/*******************************************************/

#include <iostream>
#include <cmath>
#include <fstream>

#define max(a, b) ((a > b) ? a : b);

using namespace std;

int get_skew_num(double width, double height) {
	if (width < 1 || height < 1)
		return 0;
	else {
		double temp_height = 1;
		int skew_max = floor(width);
		temp_height += (sqrt(3) / 2);
		int round = 2;
		while (temp_height <= height) {
			if (round % 2 == 0)
				skew_max += floor(width - 0.5);
			else
				skew_max += floor(width);
			temp_height += (sqrt(3) / 2);
			round++;
		}
		return skew_max;
	}
}

int main() {
	double width, height;
	int grid_max, skew_max;

	while (cin >> width >> height) {
		grid_max = floor(width) * floor(height);
		skew_max = max(get_skew_num(width, height), get_skew_num(height, width));

		if (grid_max >= skew_max)
			fp << grid_max << " grid" << endl;
		else
			fp << skew_max << " skew" << endl;
	}

	system("pause");
	return 0;

}