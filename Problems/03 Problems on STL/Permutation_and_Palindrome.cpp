#include <bits/stdc++.h>
using namespace std;

void getPalindrome(string s){
    map<char,vector<int>> M;

        for(int i = 0; i < s.length(); i++){
            M[s[i]].push_back(i);         // 1 based indexing.
        }

        int count = 0;
        for(auto i : M){
            if((i.second.size() % 2) != 0)
                count++;
        }

        if(count > 1){
            cout << "-1";
            return;
        }

        vector<int> result(s.length());
        int k = 0;

        for(auto i : M){
            int p = i.second.size();
            if(p % 2 == 0){
                for(int j = 0; j < p; j++){
                    if(j % 2 == 0){
                        result[k] = i.second.at(j);
                    }
                    else{
                        result[s.length() - k - 1] = i.second.at(j);
                        k++;
                    }
                }
            }else{
                for(int j = 0; j < p - 1; j++){
                    if(j % 2 == 0){
                        result[k] = i.second.at(j);
                    }
                    else{
                        result[s.length() - k - 1] = i.second.at(j);
                        k++;
                    }
                }
                result[s.length()/2] = i.second.at(p-1);
            }
        }

        for (int i = 0; i < result.size(); i++)
        {
            cout << (result[i] + 1) << " ";
        }
}

int main(){
    int n;
    cin >> n;
    for(int r = 0; r < n; r++){
        string s;
        cin >> s;
        getPalindrome(s);
        cout << endl;
    }

    return 0;
}