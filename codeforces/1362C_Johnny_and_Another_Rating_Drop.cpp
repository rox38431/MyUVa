#include <iostream>
#include <math.h>

using namespace std;

int main() {
    long long * table = new long long [60];
    table[0] = 1;
    long long accumu = 1;
    for (int i = 1; i < 60; i++) {
        table[i] = accumu + (i + 1);
        accumu = accumu + table[i];
    }

    for (int i = 0; i < 60; i++) {
        // cout << table[i] << endl;
    }

    int cases;
    cin >> cases;
    while (cases--) {
        long long num;
        cin >> num;

        long long ans = 0;
        int bit_index = 0;
        while (num > 0) {
            if (num % 2 == 1) {
                ans += table[bit_index];
                num -= 1;
            }
            num /= 2;
            bit_index += 1;
        }
        cout << ans << endl;
    }
    return 0;
}
