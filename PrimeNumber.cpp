#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

vector<int>printPrime(int n)
{
    vector<int>num;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i)) {
           num.push_back(i);
           // cout << i << " ";
        }
    }
    return num;
}

int main()
{
    vector<int>k;
    int i,n;
    cin>>n;
    k=printPrime(n);

    for(i=0;i<k.size();i++)
    {
        cout<<k[i]<<" ";
    }

}






