/*******************************************************/
/* UVa 315 - Network							       */
/* Author: rox38431									   */
/* Version: 2018/04/08                                 */
/*******************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void DFS(int [][100], int[], int, int);

int main() {
	int adjMatrix[100][100];
	int N;

	while (scanf("%d", &N) && N != 0)	{
		for (int i = 1; i <= N; i++)	{
			for (int j = 1; j <= N; j++) {
				adjMatrix[i][j] = 0;
			}
		}

		string s;
		while (getline(cin, s) && s != "0") {

			istringstream stream(s);
			int center, num;
			stream >> center;

			while (stream >> num) {
				adjMatrix[center][num] = 1;
				adjMatrix[num][center] = 1;
			}
		}

		int cut_point_count = 0;
		int *visited = new int[N + 1];
		
		for (int i = 1; i <= N; i++) {

			for (int j = 1; j <= N; j++)
				visited[j] = 0;
			visited[i] = 1;

			if (i == 1)
				DFS(adjMatrix, visited, 2, N);
			else
				DFS(adjMatrix, visited, 1, N);


			for (int j = 1; j <= N; j++) {
				if (visited[j] == 0) {
					cut_point_count++;
					break;
				}
			}
		}
		cout << cut_point_count << endl;
	}

	return 0;
}

void DFS(int adjMatrix[][100], int visited[], int now, int size) {
	visited[now] = 1;
	for (int i = 1; i <= size; i++) {
		if (visited[i] == 0 && adjMatrix[now][i] == 1)
			DFS(adjMatrix, visited, i, size);
	}
}