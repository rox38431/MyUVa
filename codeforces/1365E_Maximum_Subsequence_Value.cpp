#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    long long * arr = new long long [num];
    for (int i = 0; i < num; i++)
        cin >> arr[i];

    long long ans = 0;
    for (int i = 0; i < num; i++) {
        for (int j = i; j < num; j++) {
            for (int k = j; k < num; k++) {
                ans = max(ans, arr[i] | arr[j] | arr[k]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}

