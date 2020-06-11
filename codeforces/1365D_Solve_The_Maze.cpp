#include <iostream>

using namespace std;

void array_dfs(char **maze, int r, int c, int max_r, int max_c, int &good_cnt) {
    if (c-1 >= 0 && maze[r][c-1] != '#') {
        c = c - 1;
        if (maze[r][c] == 'G')
            good_cnt--;
        maze[r][c] = '#';
        array_dfs(maze, r, c, max_r, max_c, good_cnt);
        c = c + 1;
    }

    if (r+1 <= max_r && maze[r+1][c] != '#') {
        r = r + 1;
        if (maze[r][c] == 'G')
            good_cnt--;
        maze[r][c] = '#';
        array_dfs(maze, r, c, max_r, max_c, good_cnt);
        r = r - 1;
    }

    if (c+1 <= max_c && maze[r][c+1] != '#') {
        c = c + 1;
        if (maze[r][c] == 'G')
            good_cnt--;
        maze[r][c] = '#';
        array_dfs(maze, r, c, max_r, max_c, good_cnt);
        c = c - 1;
    }

    if (r-1 >= 0 && maze[r-1][c] != '#') {
        r = r - 1;
        if (maze[r][c] == 'G')
            good_cnt--;
        maze[r][c] = '#';
        array_dfs(maze, r, c, max_r, max_c, good_cnt);
        r = r + 1;
    }
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        int row, col;
        cin >> row >> col;
        
        int good_cnt = 0;
        char ** maze = new char *[row];
        for (int i = 0; i < row; i++)
            maze[i] = new char [col];

        for (int i = 0; i < row; i++)  {
            for (int j = 0; j < col; j++) { 
                cin >> maze[i][j];
                if (maze[i][j] == 'G')
                    good_cnt++;
            }
        }


        bool end = false, good_exist = false;
        for (int i = 0; i < row && end == false; i++) {
            for (int j = 0; j < col && end == false; j++) {
                if (maze[i][j] == 'G')
                    good_exist = true;

                if (maze[i][j] == 'B') {
                    if (i > 0) {
                        if (maze[i-1][j] == '.')
                            maze[i-1][j] = '#';
                        else if (maze[i-1][j] == 'G')
                            end = true;
                    }

                    if (j > 0) {
                        if (maze[i][j-1] == '.')
                            maze[i][j-1] = '#';
                        else if (maze[i][j-1] == 'G')
                            end = true;
                    }

                    if (i < row-1) {
                        if (maze[i+1][j] == '.')
                            maze[i+1][j] = '#';
                        else if (maze[i+1][j] == 'G')
                            end = true;
                    }

                    if (j < col-1) {
                        if (maze[i][j+1] == '.')
                            maze[i][j+1] = '#';
                        else if (maze[i][j+1] == 'G')
                            end = true; 
                    }       
                }
            }
        }

        if (end) {
            cout << "No" << endl;
            continue;
        }
        else if (good_exist == false) {
            cout << "Yes" << endl;
            continue;
        }
        else if (maze[row-1][col-1] == '#') {
            cout << "No" << endl;
            continue;
        }

        /*
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
        */

        array_dfs(maze, row-1, col-1, row-1, col-1, good_cnt);
        if (good_cnt == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
