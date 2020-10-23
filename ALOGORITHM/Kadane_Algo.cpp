#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
long long int n,curr_max,all_max,i;
cin>>n;
long long int a[n];

for(i=0;i<n;i++)
{
 cin>>a[i];
}
all_max=curr_max=a[0];
for(i=1;i<n;i++)
{
   if((curr_max+a[i])>a[i])
        curr_max=curr_max+a[i];
   else
        curr_max=a[i];
        cout<<"curr_max="<<curr_max<<endl;

   if(curr_max>all_max)
    all_max=curr_max;



    cout<<"all_max="<<all_max<<endl;

}
cout<<all_max<<endl;
}
