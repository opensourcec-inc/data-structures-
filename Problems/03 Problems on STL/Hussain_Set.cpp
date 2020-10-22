#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int n,m;
    cin >> n >> m;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr,arr+n);

    queue<ll> q;
    int end_p = n-1;
    int count = 0;

    for(int i = 0; i < m;i++){
        ll x;
        cin >> x;
        ll ans;
        for(;count < x;count++){

            if((end_p >= 0) && (q.empty() || arr[end_p] > q.front())){
                ans = arr[end_p];
                end_p--;
            }
            else{
                ans = q.front();
                q.pop();
            }
            
            if(ans != 0 && ((ans / 2) > 0))
                q.push(ans/2);
        }
        cout << ans << "\n";
    }
    return 0;
}