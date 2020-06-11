#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int ans = 0;
    int n;
    cin >> n;

    int * a = new int [n];
    int * count = new int[n];
    map<int, int> idx_map;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        idx_map[a[i]] = i;
    }

    for (int i = 0; i < n; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        int distance = idx_map[num] - i;
        if (distance < 0)
            distance += n;
        count[distance] += 1;
        ans = max(ans, count[distance]);
    }
    cout << ans << endl;

    return 0;
}
