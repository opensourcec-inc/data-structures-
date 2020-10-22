#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> v[200];
vector<int> rev_v[200];
int visited[200];
vector<int> stacki;

void dfs(int i)
{
    visited[i] = 1;
    for (auto x : v[i])
    {
        if (!visited[x])
        {
            dfs(x);
        }
    }
    stacki.push_back(i);
}

void new_dfs(int i)
{
    visited[i] = 1;
    for (auto x : rev_v[i])
    {
        if (!visited[x])
        {
            new_dfs(x);
        }
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        rev_v[y].push_back(x);
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    memset(visited, 0, sizeof(visited));

    int count = 0;
    for (int i = stacki.size() - 1; i >= 0; i--)
    {
        int node = stacki[i];
        if (!visited[node])
        {
            new_dfs(node);
            count++;
            // cout << stacki[i] << endl;
        }
    }
    cout << count << endl;

    return 0;
}