#include<bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(0); cin.tie(0);
#define ll long long int
#define endl "\n";
#define mod 1000000007
#define pii pair<int,int>
#define pll pair<ll,ll>
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll mxN = 1e5 + 1;


vector<int> v[10005];
vector<int> visited(10005);
vector<int> length(10005);

void dfs(int i, int leng)
{
	visited[i] = 1;
	length[i] = leng;
	for (auto x : v[i])
	{
		if (!visited[x])
			dfs(x, length[i] + 1);
	}
}

int main()
{
	int n;
	cin >> n;
	int a, b;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i <= n + 2; i++)
	{
		visited[i] = 0;
	}
	dfs(1, 0);
	int new_dfs_element;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (length[i] > ans)
		{
			new_dfs_element = i;
			ans = length[i];
		}
	}
	for (int i = 1; i <= n + 1; i++)
	{
		visited[i] = 0;
		length[i] = 0;
	}
	dfs(new_dfs_element, 0);
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (length[i] > ans)
		{
			//new_dfs_element=i;
			ans = length[i];
		}
	}
	cout << ans << endl;
	return 0;
}