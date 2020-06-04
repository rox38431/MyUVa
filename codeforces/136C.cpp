#include <iostream>

using namespace std;

int main() {
	int testcases = 0;
	cin >> testcases;

	while (testcases--) {
	    int n, x;
	    cin >> n >> x;
	    x -= 1;
            
	    int * arr;
	    arr = new int [n];
	    arr[x] = 1;  // key node
	    int key_neighbor = 0;

	    for (int i = 0; i < n - 1; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		node1--;
		node2--;
		
		if (node1 == x || node2 == x)
		    key_neighbor += 1;
	    }

	    if (key_neighbor == 1)
		cout << "Ayush" << endl;
	    else if (key_neighbor == 0)
		cout << "Ayush" << endl;
	    else {
	        int num = n - 3;
		if (num % 2 == 0)
		    cout << "Ashish" << endl;
		else
		    cout << "Ayush" << endl;
	    }
    }

    return 0;
}

