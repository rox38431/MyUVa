#include <iostream>
#include <string>
using namespace std;

int main ()	{
	string num;

	while (cin >> num && num != "0")	{
		int sum = 0, degree = 1;
	
		for (int i = 0; i < num.length(); i++)
			sum += num[i] - '0';
		
		if (sum % 9 == 0)	{
			while (sum > 9)	{
				int temp = 0;
				while (sum > 0)	{
					temp += sum % 10;
					sum /= 10;
				}
				sum = temp;
				degree++;
			}
				
			cout << num << " is a multiple of 9 and has 9-degree " << degree << "." << endl;
		}
		else
			cout << num << " is not a multiple of 9." << endl;
	}
	
	return 0;
}



	
