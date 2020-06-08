#include <iostream>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    while (cases--) {
        int even = 0, odd = 0;
        int n, x;
        cin >> n >> x;
        
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if (num % 2 == 0)
                even++;
            else
                odd++;
        }

        if (odd == 0) {
            cout << "No" << endl;
            continue;
        }

        if (x % 2 == 0) {
            if (even == 0) {
                cout << "No" << endl;
                continue;
            }
            if (even % 2 == 0) 
                even--;
            if (even + odd >= x)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else {
            if (even == 0 and odd >= x) {
                cout << "Yes" << endl;
                continue;
            }
            if (even > 0 && even % 2 == 1)
                even--;
            if (even + odd >= x)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}
