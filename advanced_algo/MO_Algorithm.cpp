#include<bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(0); cin.tie(0);
#define ll long long int
#define ull unsigned long long
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define endl "\n";
#define BLOCK 555
#define mod 1000000007
const ll MAX_SIZE = 1e5 + 1;
const double PI = 3.14159265359;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct query {
    int l;
    int r;
    int i;
};

query Q[200001];
int ar[30001];
int ans[200001];
int fre[1000001];
int cnt = 0;


bool comp(query a, query b)
{
    if (a.l / BLOCK != b.l / BLOCK)
        return a.l / BLOCK < b.l / BLOCK;

    return a.r < b.r;
}

void add(int pos)
{
    fre[ar[pos]]++;
    if (fre[ar[pos]] == 1)
        cnt++;
}

void remove(int pos)
{
    fre[ar[pos]]--;
    if (fre[ar[pos]] == 0)
        cnt--;
}


int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i;
        Q[i].l--;
        Q[i].r--;
    }

    sort(Q, Q + q, comp);
    int ML = 0;
    int MR = -1;
    for (int i = 0; i < q; i++)
    {
        int L = Q[i].l;
        int R = Q[i].r;
        int idx = Q[i].i;


        // extending range
        while (MR < R)
        {
            MR++;
            add(MR);
        }
        while (ML > L)
        {
            ML--;
            add(ML);
        }

        // reducing range

        while (MR > R)
        {
            remove(MR);
            MR--;
        }
        while (ML < L)
        {
            remove(ML);
            ML++;
        }

        ans[idx] = cnt;
    }
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
}