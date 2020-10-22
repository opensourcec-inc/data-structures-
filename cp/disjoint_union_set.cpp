#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n, m;
list<pair<int, int>> l;
int parent[200];

int findset(int i, int parent[])
{
	if (parent[i] == -1)
	{
		return i;
	}
	// path compression optimisation
	return (parent[i] = findset(parent[i], parent));
}

void union_set(int x, int y, int parent[], int rank[])
{
	int s1 = findset(x, parent);
	int s2 = findset(y, parent);
	if (s1 != s2)
	{
		if (rank[s2] <= rank[s1])
		{
			parent[s2] = s1;
			rank[s1] += rank[s2];
		}
		else
		{
			parent[s1] = s2;
			rank[s2] += rank[s1]
		}
	}
}

bool contains_cycle()
{
	int *parent = new int[n];
	int *rank = new int[n];
	for (int i = 0; i < n; i++)
	{
		parent[i] = -1;
		rank[i] = 1;
	}
	for (auto edge : l)
	{
		int i = edge.first;
		int j = edge.second;
		int s1 = findset(i, parent);
		int s2 = findset(j, parent);

		if (s1 != s2)
		{
			union_set(s1, s2, parent, rank);
		}
		else
		{
			cout << "same parents" << " " << s1 << " " << s2 << endl;
			return true;
		}
	}
	delete [] parent;
	return false;
}

int main()
{
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		l.push_back(make_pair(x, y));
	}
	cout << contains_cycle() << endl;
	return 0;
}