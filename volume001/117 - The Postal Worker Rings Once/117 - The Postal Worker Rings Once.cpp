/*******************************************************/
/* UVa 117 - The Postal Worker Rings Once              */
/* Author: rox38431									   */		
/* Version: 2018/03/31                                 */
/*******************************************************/

#include <iostream>
#include <string>
#include <vector>

#define min(a, b) ((a < b) ? a : b);

using namespace std;

int floyd_warshall(int **, int*, int);

int main() {
	string street;
	int shortest_route = 0;
	int street_count = 0;
	int node_count = 0;
	int encode[26];
	vector<string> street_vector;

	for (int i = 0; i < 26; i++) {
		encode[i] = -1;
	}

	while (cin >> street) {
		if (street != "deadend") {
			street_vector.push_back(street);

			int start = street[0] - 97;
			int end = street[street.length() - 1] - 97;

			if (encode[start] == -1) {
				encode[start] = node_count++;
			}
			if (encode[end] == -1) {
				encode[end] = node_count++;
			}
		}
		else {
			vector<string>::iterator itor;
			int **adjList = new int *[node_count];
			int *degree = new int[node_count];

			for (int i = 0; i < node_count; i++) {
				adjList[i] = new int[node_count];
				for (int j = 0; j < node_count; j++){
					if (i == j)
						adjList[i][j] = 0;
					else
						adjList[i][j] = 1000000;
				}
				degree[i] = 0;
			}


			for (itor = street_vector.begin(); itor != street_vector.end(); ++itor) {
				string s = *itor;
				int start = encode[s[0] - 97];
				int end = encode[s[s.length() - 1] - 97];
				shortest_route += s.length();

				degree[start]++;
				degree[end]++;

				if (adjList[start][end] > s.length()) {
					adjList[start][end] = s.length();
					adjList[end][start] = s.length();
				}
			}
			shortest_route += floyd_warshall(adjList, degree, node_count);
			cout << shortest_route << endl;

			shortest_route = 0;
			street_count = 0;
			street_vector.clear();
		}
	}

	return 0;
}

int floyd_warshall(int **adjList, int *degree, int size) {
	int node_a = -1, node_b = -1;
	for (int i = 0; i < size; i++) {
		if (degree[i] % 2 == 1 && node_a == -1) {
			node_a = i;
		}
		else if (degree[i] % 2 == 1 && node_a != -1) {
			node_b = i;
		}
	}

	if (node_a == -1 && node_b == -1)
		return 0;
	else {
		for (int k = 0; k < size; k++) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					adjList[i][j] = min(adjList[i][j], adjList[i][k] + adjList[k][j]);
				}
			}
		}

		return adjList[node_a][node_b];
	}
}