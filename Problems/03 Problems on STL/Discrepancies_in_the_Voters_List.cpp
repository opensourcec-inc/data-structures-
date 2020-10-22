#include <bits/stdc++.h>
using namespace std;

int main(){
    int p,q,r;
    cin >> p >> q >> r;
    int x = p+q+r;
    unordered_map<int,int> M;
    vector<int> result;

    for(int i = 0; i < x; i++){
        int s;
        cin >> s;
        M[s]++;
    }

    for(auto i : M){
        if(i.second > 1)
            result.push_back(i.first);
    }

    sort(result.begin(),result.end());

    cout << result.size() << endl;

    for(int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
}