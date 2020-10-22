#include<bits/stdc++.h>
using namespace std;

int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char a[200][200];
int r, c;
void flood_fill(char ch, char col, int start, int end)
{
	if (start < 0 || end < 0 || start > r || end > c)
		return;

	if (a[start][end] != ch)
	{
		return;
	}

	a[start][end] = col;
	for (int i = 0; i < 4; i++)
	{
		flood_fill(ch, col, start + dx[i], end + dy[i]);
	}
	return ;
}
int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
		}
	}
	int strtpos_x, strtpos_y;
	cin >> strtpos_x >> strtpos_y;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}

	flood_fill('.', 'r', strtpos_x, strtpos_y);

	cout << endl;
	cout << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}