#include <iostream>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int n;
        cin >> n;

        int prev = 0;
        bool increasing = true;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a < prev) 
                increasing = false;
            prev = a;
        }

        bool zero = false, one = false;
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            if (b == 0)
                zero = true;
            else
                one = true;
        }

        if (increasing)
            cout << "Yes" << endl;
        else if (zero && one)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    }
    return 0;
}
