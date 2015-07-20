#include <iostream>
using namespace std;

int main ()	{
	int stack[50], stack_num, count = 1;
	
	while (cin >> stack_num && stack_num != 0)	{
		int aver = 0, ans = 0;

		for (int i = 0; i < stack_num; i++)	{
			cin >> stack[i];
			aver += stack[i];
		}
	
		aver /= stack_num;

		for ( int i = 0; i < stack_num; i++)	{
			if (stack[i] > aver)
				ans += stack[i] - aver;
		}
		
		cout << "Set #" << count++ << endl;
		cout << "The minimum number of moves is " << ans << "." << endl << endl;
	}

	return 0;
}			
		
