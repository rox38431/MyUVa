#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    while (cases--) {
        int rows, cols;
        cin >> rows >> cols;

        int * row_status = new int [rows];
        int * col_status = new int [cols];
        int rest_rows = rows;
        int rest_cols = cols;

        for (int i = 0; i < rows; i++) 
            row_status[i] = 0;
        for (int i = 0; i < cols; i++)
            col_status[i] = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int claim;
                cin >> claim;
                if (claim == 1) {
                    if (row_status[i] == 0) {
                        row_status[i] = 1;
                        rest_rows--;
                    }
                    if (col_status[j] == 0) {
                        col_status[j] = 1;
                        rest_cols--;
                    }
                }
            }
        }

        int rest_step = min(rest_rows, rest_cols);
        if (rest_step % 2 == 0)
            cout << "Vivek" << endl;
        else
            cout << "Ashish" << endl;
    }

    return 0;
}
