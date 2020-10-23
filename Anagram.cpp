#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t,i,f;
	vector<int>hs(26,0);
	cin>>t;
	string s1,s2;
	while(t--)
	{
	    f=0;
	    vector<int>hs(26,0);
	    cin>>s1>>s2;
/*	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	if(s1==s2)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	}
*/
   /* for(i=0;i<hs.size();i++)
    {
        cout<<hs[i];
    }
   cout<<endl;*/

   cout<<"s1="<<s1<<endl;
   cout<<"s2="<<s2<<endl;


    for(i=0;i<s1.size();i++)
    {

        hs[s1[i]-97]++;
        cout<<s1[i];
    }
    cout<<endl;
    for(i=0;i<s2.size();i++)
    {

        hs[s2[i]-97]--;
        cout<<s2[i];
    }
    cout<<endl;
    for(i=0;i<hs.size();i++)
    {
        if(hs[i]!=0)
        {
            cout<<"NO"<<endl;
            break;
        }
    }

        if(i==26)
        cout<<"YES"<<endl;

    //for(i=0;i<hs.size();i++)
    //cout<<hs[i]<<" ";
	}

	return 0;
}
