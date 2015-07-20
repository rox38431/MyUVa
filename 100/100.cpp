#include <iostream>
using namespace std;

int main()
{
	int start, end;

	while (cin >> start >> end)
	{


		int max_cycle = -1;

		for (int i = ((start <= end) ? start : end); i <= ((start <= end) ? end : start); i++)
		{
			int temp = i, temp_cycle = 1;
			while (temp != 1)
			{
				if (temp % 2 == 1)
					temp = temp * 3 + 1;
				else
					temp = temp / 2;
				temp_cycle++;
			}
			if (temp_cycle > max_cycle)
				max_cycle = temp_cycle;
		}

		cout << start << " " << end << " " << max_cycle << endl;

	}

	return 0;
}
