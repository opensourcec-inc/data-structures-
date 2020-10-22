/*   Author : UJJWAL TRIPATHI   */


#include<bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(0); cin.tie(0);
#define ll long long int
//#define forward(i,a,b) for(int i=a;i<=b;i++)
//#define backward(i,a,b) for(int i=a;i>=b;i--)
//#define FOR(m) above(i,1,m)
//#define For(m) above(i,0,m)
#define endl "\n";
#define mod 1000000007
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int n;

vector<int> visited(5);

void dfs(int k, vector<int> v[])
{
	visited[k] = 1;
	cout << k << "->";
	for (int u : v[k])
	{
		if (visited[u] == 0)
			dfs(u, v);
	}
	return;
}


int main()

{
	int a, b;
	cin >> n;
	vector<int> v[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << "->";
		}
		cout << endl;
	}
	*/
	for (int i = 0; i < 5; i++)
	{
		visited[i] = 0;
	}
	//memset(&visited, 0, sizeof(visited));
	dfs(0, v);
	return 0;
}