/*******************************************************/
/* UVa 112 - Tree Summing			    		       */
/* Author: rox38431									   */
/* Version: 2018/04/10                                 */
/*******************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

struct Node {
	int value;
	Node *left_child;
	Node *right_child;
};

Node *build_tree(int);
bool DFS(Node *, int, int);

#define max(a, b) ((a > b) ? a : b);

int main() {
	int need_sum = 0;
	char input_char;

	Node *root_pointer = new Node();

	while (cin >> need_sum) {
		cin >> input_char;
		root_pointer->left_child = build_tree(1);

		if (root_pointer->left_child == NULL)
			cout << "no" << endl;
		else {
			bool result = DFS(root_pointer->left_child, need_sum, 0);
			if (result == false)
				cout << "no" << endl;
		}
	}
	return 0;
}

Node *build_tree(int i) {
	char input_char;
	string value;
	int child_count = 0;
	Node *new_node = new Node();


	while (cin >> input_char && input_char != ')') {
		if (input_char == ' ')
			continue;
		else if (input_char == '(') {
			if (child_count == 0) {
				new_node->left_child = build_tree(i + 1);
				child_count++;
			}
			else
				new_node->right_child = build_tree(i + 1);
		}
		else
			value += input_char;
	}

	if (value.length() == 0){
		return NULL;
	}
	else {
		istringstream stream(value);
		stream >> new_node->value;
		return new_node;
	}
}

bool DFS(Node *root, int need_sum, int partial_sum) {
	if (root == NULL)
		return false;

	if (root->left_child == NULL && root->right_child == NULL) {
		if (need_sum == partial_sum + root->value) {
			cout << "yes" << endl;
			return true;
		}
		else
			return false;
	}
	else {
		bool left_result = DFS(root->left_child, need_sum, partial_sum + root->value);

		if (left_result)
			return true;
		else
			return DFS(root->right_child, need_sum, partial_sum + root->value);
	}
}