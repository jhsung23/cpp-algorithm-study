#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct node {
	char left;
	char right;
};

vector<node> tree(26);

void preorder(char root) {
	if (root == '.') return;
	else {
		cout << root;
		preorder(tree[root-'A'].left);
		preorder(tree[root - 'A'].right);
	}
}
void inorder(char root) {
	if (root == '.') return;
	else {
		inorder(tree[root - 'A'].left);
		cout << root;
		inorder(tree[root - 'A'].right);
	}
}
void postorder(char root) {
	if (root == '.') return;
	else {
		postorder(tree[root - 'A'].left);
		postorder(tree[root - 'A'].right);
		cout << root;
	}
}
int main() {
	int n;
	char a, b, c;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		tree[a-'A'].left = b;
		tree[a-'A'].right = c;
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');

	return 0;

}
