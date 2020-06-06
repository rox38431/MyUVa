#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        string input;
        cin >> input;

        int len = input.length();
        int num_0 = 0, num_1 = 0;
	    int ** count = new int *[input.length()];
	    for (int i = 0; i < len; i++)
	        count[i] = new int [2];
            
        int first_num = input[0];
        count[0][0] = count[0][1] = 0;
        if (first_num == '0') {
            count[0][0] = 1;
            num_0 += 1;
        }
        else {
            count[0][1] = 1;
            num_1 += 1;
        }

        for (int i = 1; i < len; i++) {
            count[i][0] = count[i-1][0];
            count[i][1] = count[i-1][1];
            if (input[i] == '0') {
                count[i][0] += 1;
                num_0 += 1;
             }
            else {
                 count[i][1] += 1;
                 num_1 += 1;
             }
        }

        int cost_01 = 10000;
        int cost_10 = 10000;
        for (int i = 0; i < len; i++) {
            if (input[i] == '0') {
                cost_01 = min(cost_01, count[i][1] + (num_0-count[i][0]));
                cost_10 = min(cost_10, count[i][0]-1 + (num_1-count[i][1]));
            }
        }

        int smallest = min(cost_01, cost_10);
        smallest = min(smallest, num_0);
        smallest = min(smallest, num_1);
        cout << smallest << endl;
    }
    return 0;
}
