#include <bits/stdc++.h>
using namespace std;


// function to build  trees.//

void buildtree(int *tree, int *a, int index, int s, int e)
{
	if (s > e) {
		return;
	} // Base case.}

	// Base case if leaf node.
	if (s == e)
	{
		tree[index] = a[s];
		return ;
	}

	// Recursive case
	int mid = (s + e) / 2;
	// Left subtree

	buildtree(tree, a, 2 * index, s, mid);

	// Right subtree

	buildtree(tree, a, 2 * index + 1, mid + 1, e);


	int left = tree[2 * index];
	int right = tree[2 * index + 1];

	tree[index] = min(left, right);

}
/// Function for query return min element ///

int query(int *tree, int index, int s, int e, int qs, int qe)
{
	// 3 case


	//1-No overlap return the infinte.

	if (qe < s || qs > e)
	{
		return (INT_MAX);
	}

	// 2-Complete overlap return the tree index element

	if (e <= qe && s >= qs)
	{
		return (tree[index]);
	}

	// 3-Partial overlap Call both left and right side

	if (qe > s || qs < e)
	{
		int mid = (s + e) / 2;

		int left = query(tree, 2 * index, s, mid, qs, qe);
		int right = query(tree, 2 * index + 1, mid + 1, e, qs, qe);
		return (min(left, right));
	}
	return 0;
}

// Funtion update the given node by given value ///

void updatenode(int *tree, int index, int s, int e, int i, int value)
{
	//NO overlap
	if (i > e || i < s)
	{
		return;
	}

	// OR on leaf node
	if (s == e)
	{
		tree[index] = value;
		return;
	}

	// lying in Range;
	int mid = (s + e) / 2;
	updatenode(tree, 2 * index, s, mid, i, value);
	updatenode(tree, 2 * index + 1, mid + 1, e, i, value);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}

/// Update the range of element by given value ////


void rangeupdate(int *tree, int index, int s, int e, int rs, int re, int value)
{
	// NO overlap
	if (rs > e || re < s)
	{
		return;
	}
// reach leaf node
	if (s == e)
	{
		tree[index] += value;
		return;
	}
	// lying in range call both left and right
	int mid = (s + e) / 2;
	rangeupdate(tree, 2 * index, s, mid, rs, re, value);
	rangeupdate(tree, 2 * index + 1, mid + 1, e, rs, re, value);
	tree[index] += min(tree[2 * index], tree[2 * index + 1]);
	return;
}


// LAZY Propogation //

void update_segment_tree_range_lazy(int *tree, int *lazytree, int index, int s, int e, int rs, int re, int value)
{

	//  make sure all propagation is  done at index.if not update tree
	// at index and its children for lazy propagation.

	if (lazytree[index] != 0)
	{
		tree[index] += lazytree[index];
		// if not a leaf node
		if (s != e)
		{
			lazytree[2 * index] += lazytree[index];
			lazytree[2 * index + 1] += lazytree[index];
		}
		lazytree[index] = 0;
	}

	if (s > e || rs > e || re < s)
		return;

	// complete overlap

	if (rs <= s && re >= e)
	{
		tree[index] += value;
		if (s != e)
		{
			lazytree[2 * index] += value;
			lazytree[2 * index + 1] += value;
		}
		return;
	}

	// Partial overlap look both left and right
	int mid = (s + e) / 2;
	// look leftsubtree;
	update_segment_tree_range_lazy(tree, lazytree, 2 * index, s, mid, rs, re, value);
	// look right one
	update_segment_tree_range_lazy(tree, lazytree, 2 * index + 1, mid + 1, e, rs, re, value);

	tree[index] += min(tree[2 * index], tree[2 * index + 1]);
}
int main()
{
	int a[] = {1, 3, 2, 2, 4, 7};
	int n = 6;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	// Build the tree array

	//	int *tree = new int[4 * n + 1];
	int tree[4 * n + 1];
	// also can be declare as---- int tree[4*n+1]---;


	int index = 1;
	int s = 0;
	int e = n - 1;

	//  build tree function //

	buildtree(tree, a, index, s, e);

	//update the node//

	/*
		 int value_node_update,position_update;
		cin>>value>>position_update;;
		updatenode(tree, 1, s, e,position_update,value_node_update);

	 */


	// update the range//
	/*
	    int value_range_update,range_start,range_end;
		cin>>value_range_update>>range_start>>range_end;
		rangeupdate(tree, 1, s, e, range_start,range_end,value_range_update);
	*/


	// lazy Propogation //
	int lazytree[4 * n + 2];
	for (int i = 0; i < 4 * n + 2; i++)
	{
		lazytree[i] = 0;
	}
	update_segment_tree_range_lazy(tree, lazytree, 1, s, e, 0, 4 , 10);
	// query //
	int no_of_query;
	cin >> no_of_query;
	while (no_of_query--)
	{
		int qs, qe;
		cin >> qs >> qe;
		cout << "min value between range is   ";
		cout << query(tree, 1, s, e, qs, qe) << endl;
	}

	return 0;
}