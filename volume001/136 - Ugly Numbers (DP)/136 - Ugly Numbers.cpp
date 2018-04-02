/*******************************************************/
/* UVa 136 - Ugly Numbers				               */
/* Author: rox38431									   */
/* Version: 2018/04/02                                 */
/*******************************************************/

#include <iostream>

using namespace std;

int main() {
	int count = 1;
	int max = 1;
	int ugly[1500];
	ugly[0] = 1;

	for (int i = 1; i < 1500; i++) {
		max = ugly[i - 1];
		int max_2 = -1, max_3 = -1, max_5 = -1;
		int j = 0;
		while (max_2 <= max || max_3 <= max || max_5 <= max) {
			if (max_2 <= max)
				max_2 = ugly[j] * 2;
			if (max_3 <= max)
				max_3 = ugly[j] * 3;
			if (max_5 <= max)
				max_5 = ugly[j] * 5;
			j++;
		}

		int min = max_2;
		if (min > max_3)
			min = max_3;
		if (min > max_5)
			min = max_5;
		ugly[i] = min; 
	}

	cout << "The 1500\'th ugly number is " << ugly[1499] << ".\n";
	
	return 0;
}

