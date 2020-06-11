#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    while(cases--) {
        int num;
        cin >> num;

        map<int, int> num_map;
        map<int, int>::iterator iter;
        int * arr = new int [num];
        for (int i = 0; i < num; i++) {
            cin >> arr[i];
            num_map[arr[i]] = 0;
        }

        int ans = 1e5;
        if (num % 2 == 1) 
            cout << -1 << endl;
        else {
            for (int i = 1; i < num; i++) {
                int R = arr[0] ^ arr[i];
                for (int j = 1; j < num; j++) {
                    int xor_result = R ^ arr[j];
                    iter = num_map.find(xor_result);
                    if (iter == num_map.end())
                        break;
                    else if (j == num - 1)
                        ans = min(ans, R);
                }
            }
            if (ans != 1e5)
                cout << ans << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}
