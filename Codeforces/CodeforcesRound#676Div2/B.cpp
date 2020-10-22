#include<bits/stdc++.h>
using namespace std;
		
#define ar array<ll, 2>
#define ll long long
#define in insert
#define pb push_back
#define vt vector
#define P_Q(x) priority_queue<x>
#define p_q(x) priority_queue<x, vector<x>, greater<x>>
#define For(i, n) for(ll i = 0; i < n; i++)
#define Rev(i, n) for(ll i = n-1; i >= 0; i--)
#define FOR(i, n) for(ll i = 1; i <= n; i++)
#define REV(i, n) for(ll i = n; i >= 1; i--)
#define Rep(i,a,b) for(ll i = a; i <= b; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()

const ll mod = 1e9L + 7;
const ll INF = 1e18L + 5;
const ll mxN = 2e5 + 1;
ll n;
vt<string> s;

void solve(){
	cin >> n;
	s.resize(n);
	For(i, n){
		cin >> s[i];
	}
	ll ops = 0;
	ops += (s[0][1] == '0') + (s[1][0] == '0') + (s[n-1][n-2] == '1') + (s[n-2][n-1] == '1');
	if(ops <= 2){
		cout << ops << '\n';
		if(s[0][1] == '0') {
			cout << 1 << " " << 2 << '\n';
		}
		if(s[1][0] == '0') {
			cout << 2 << " " << 1 << '\n';
		}
		if(s[n-1][n-2] == '1') {
			cout << n << " " << n - 1 << '\n';
		}
		if(s[n-2][n-1] == '1'){
			cout << n-1 << " " << n << '\n';
		}
	}else{
		cout << 4 - ops << '\n';
		if(s[0][1] == '1') {
			cout << 1 << " " << 2 << '\n';
		}
		if(s[1][0] == '1') {
			cout << 2 << " " << 1 << '\n';
		}
		if(s[n-1][n-2] == '0') {
			cout << n << " " << n - 1 << '\n';
		}
		if(s[n-2][n-1] == '0'){
			cout << n-1 << " " << n << '\n';
		}
	}
}

int main()
{
    ios::sync_with_stdio(0);  cin.tie(0);
    ll t = 1;
    cin >> t;
    FOR(tt, t) solve();
    return 0;
}