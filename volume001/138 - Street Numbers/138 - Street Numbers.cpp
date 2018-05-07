/*******************************************************/
/* UVa 138 - Street Numbers							   */
/* Author: rox38431									   */
/* Version: 2018/05/07                                 */
/*******************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	int count = 0;

	double programmer_house = 6;
	while (count != 10) {
		double last_house = (-1 + sqrt(1 + 8 * programmer_house * programmer_house)) / 2;
		if (modf(last_house, &last_house) == 0.0) {
			cout << fixed << setw(10) << setprecision(0) << programmer_house;
			cout << fixed << setw(10) << setprecision(0) << last_house << endl;
			count++;
		}
		programmer_house++;
	}

	return 0;
}

//int main() {
//	int count = 0;
//	long long end_house = 8;
//	while (count != 10) {
//		//long long programmer_house = ;
//		double programmer_house = sqrt((end_house * (end_house + 1)) / 2);
//		
//		//int int_part = (int)round(result);
//		if (modf(programmer_house, &programmer_house) == 0.0) {
//			count++;
//			//cout << (y * (y + 1)) / 2 << " " << result << " " << y << endl;
//			cout << fixed << setw(10) << setprecision(0) << programmer_house;
//			cout << fixed << setw(10) << setprecision(0) << end_house << endl;
//			}
//		end_house++;
//	}
//	return 0;
//}