// Segment Tree : BUILD, QUERY, POINT UPDATE, RANGE UPDATE
// Range Min Query Using Segment Tree.
#include <bits/stdc++.h>
using namespace std;

void init() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

// Build segement tree
void buildTree(int *a, int s, int e, int *tree, int index) {

	// base case
	if (s == e) {
		tree[index] = a[s];
		return;
	}
	// recursive case
	int mid = (s + e) >> 1;

	// post order traversal
	buildTree(a, s, mid, tree, 2 * index);
	buildTree(a, mid + 1, e, tree, 2 * index + 1);

	// taking the minimum of the left node i.e 2 * i and right node 2*i+1. If i(1 indexing) is the parent of both left and right node.
	tree[index] = min(tree[2 * index] , tree[2 * index + 1]);
	return;
}
// Query the segment tree
int query(int *tree, int ss, int se, int qs, int qe, int index) {

	// Complete Overlap
	if (ss >= qs and se <= qe) {
		return tree[index];
	}

	// No Overlap
	if (qe<ss or qs>se) {
		return INT_MAX;
	}

	// Partial Overlap
	int mid = (ss + se) >> 1;
	int left = query(tree, ss, mid, qs, qe, 2 * index);
	int right = query(tree, mid + 1, se, qs, qe, 2 * index + 1);

	return min(left, right);
}

// Point Update : Update any index of the array
void updatePoint(int *tree, int ss, int se, int idx, int increment, int index) {
	// Out of bounds case
	if (idx < ss or idx > se) {
		return;
	}

	// leaf node
	if (ss == se) {
		tree[index] += increment;
		return;
	}
	int mid = (ss + se) >> 1;
	updatePoint(tree, ss, mid, idx, increment, 2 * index);
	updatePoint(tree, mid + 1, se, idx, increment, 2 * index + 1);

	// update all the nodes from leaf to the root
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}

void updateRange(int *tree, int ss, int se, int l, int r, int inc, int index) {
	// Out of bounds
	if (l > se or r < ss) {
		return;
	}

	// leaf node
	if (ss == se) {
		tree[index] += inc;
		return;
	}
	// recursive
	int mid = (ss + se) >> 1;
	updateRange(tree, ss, mid, l, r, inc, 2 * index);
	updateRange(tree, mid + 1, se, l, r, inc, 2 * index + 1);

	// updating the parent node
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;

}

int main() {
	init();
	int a[] = {1, 3, 2, -5, 6, 4};
	int size = sizeof(a) / sizeof(int);

	// max size of segement tree is <= 4n+1
	int *tree = new int[4 * size + 1];

	// build segment tree
	buildTree(a, 0, size - 1, tree, 1);

	// uncomment this for point update
	// updatePoint(tree, 0, size - 1, 3, 10, 1);

	// range update query
	updateRange(tree, 0, size - 1, 3, 5, +10, 1);

	int q;
	cin >> q;

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << query(tree, 0, size - 1, l, r, 1) << endl;
	}

	return 0;
}
