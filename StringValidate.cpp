#include<iostream>
//#include<string.h>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int i,f=1;
  string s;
  getline(cin,s);
  cout<<"size="<<s.size()<<endl;
  for(i=0;i<s.size();i++)
  {
      if((!(s[i]>=65 && s[i]<=90))&&(!(s[i]>=97 && s[i]<=122))&&(!(s[i]>=48 && s[i]<=57))&&(!(s[i]==32)))
      {
        f=0;
        break;
      }
  }
  if(f==0)
    cout<<"Invalid String"<<endl;
  else
    cout<<"Valid String"<<endl;
}
