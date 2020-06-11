#include <iostream>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        long long a, b;
        cin >> a >> b;
       
        if (a < b)
            swap(a, b);
        
        int cnt = 0, tmp_cnt = 0;
        while(true) {
            if (a >= b) {
                if (a == b) {
                    if (tmp_cnt != 0)
                        cnt++;
                    cout << cnt << endl;
                    break;
                }
                else if (a % 2 == 1) {
                    cout << -1 << endl;
                    break;
                }
                
                a = a / 2;
                tmp_cnt++;
                if (tmp_cnt == 3) {
                    tmp_cnt = 0;
                    cnt++;
                }
            }
            else {
                cout << -1 << endl;
                break;
            }
        }
        
    }
    return 0;
}
