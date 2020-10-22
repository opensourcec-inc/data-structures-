#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,n1,n2,maxi,num,x,y;
     cin>>t;
    while(t--)
    {
        cin>>x>>y;
        maxi=0;
        vector<string>s1;
        vector<string>s2;
        string str1,str2,st,sd;
        cin>>str1>>str2;

        /* for(i=0;i<3;i++){
               cin>>st;
           s1.push_back(st);
        }*/

        n1=str1.size();
        n2=str2.size();

        for(i=0; i<n1; i++)
        {
            for(j=1; j<=n1-i; j++)
            {
                st=str1.substr(i,j);
                s1.push_back(st);
            }
        }

        for(i=0; i<n2; i++)
        {
            for(j=1; j<=n2-i; j++)
            {
                st=str2.substr(i,j);
                s2.push_back(st);
            }
        }

        for(i=0; i<s1.size(); i++)
        {
            // cout<<"s1[i]"<<s1[i]<<endl;
            for(j=0; j<s2.size(); j++)
            {
                // cout<<"s2[j]"<<s2[j]<<endl;
                //num=s1[i].compare(s2[j]);
                if(s1[i]==s2[j] && (s1[i].size())>maxi)
                {
                    maxi=s1[i].size();
                    sd=s1[i];
                }

            }
        }

        cout<<maxi<<endl;
        // cout<<"string"<<sd<<endl;

    }




}

