#include <iostream>
#define I 32767
using namespace std;

void join(int set[], int i, int j)
{
	if (set[i] < set[j])
	{
		set[i] += set[j];
		set[j] = i;
	}
	else
	{
		set[j] += set[i];
		set[i] = j;
	}
}

int find(int set[], int i)
{
	int x = i, v = 0;
	while (set[x] > 0)
		x = set[x];
	while (i != x)
	{
		v = set[i];
		set[i] = x;
		i = v;
	}
	return x;
}

void Kruskal(int** edge, int n, int e)
{
	int t[2][10];
	int set[10], included[10], min, j, k = 0, u = 0, v = 0;
	for (int i = 0; i < 10; i++)
	{
		set[i] = -1;
		included[i] = 0;
	}
	int i = 0;
	while (i < e - 1)
	{
		min = I;
		for (j = 0; j < n; j++)
		{
			if (included[j] == 0 && edge[2][j] < min)
			{
				min = edge[2][j];
				u = edge[0][j];
				v = edge[1][j];
				k = j;
			}
		}
		if (find(set, u) != find(set, v))
		{
			t[0][i] = u;
			t[1][i] = v;
			join(set, find(set, u), find(set, v));
			i++;
		}

		included[k] = 1;
	}
	for (i = 0; i < e - 1; i++)
	{
		cout << "(" << t[0][i] << ", " << t[1][i] << ")" << endl;
	}
}
int main()
{
	int** edge, n, e;
	char ans = 'Y';
	cout << "Enter number of nodes : ";
	cin >> e;
	cout << "Enter the number of edges : ";
	cin >> n;
	edge = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		edge[i] = new int[e+1];
	}
	cout << "\nEnter the starting vertex, ending vertex, cost of the edge : ";
	for(int i = 0; i < n; i++)
	{
		cout << "edge " << i + 1 << " : ";
		cin >> edge[0][i] >> edge[1][i] >> edge[2][i];
	}
	Kruskal(edge, n, e);
	return 0;
}
