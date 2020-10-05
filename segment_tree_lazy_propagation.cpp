#include<bits/stdc++.h>
using namespace std;

int create(int *a, int *seg, int low, int high, int pos)
{
	if(low==high)
	{
		seg[pos]=a[low];
		return seg[pos];
	}
	int mid=(low+high)/2;
	seg[pos]=min(create(a,seg,low,mid,(2*pos+1)),create(a,seg,mid+1,high,(2*pos+2)));
	return seg[pos];
}

int rangeMinQuery(int *seg, int qlow, int qhigh, int low, int high, int pos)
{
	if(qlow<=low && qhigh>=high)
	{
		return seg[pos];
	}
	if(qlow>high || qhigh<low)
	{
		return INT_MAX;
	}
	int mid=(low+high)/2;
	return min(rangeMinQuery(seg,qlow,qhigh,low,mid,(2*pos)+1),rangeMinQuery(seg,qlow,qhigh,mid+1,high,(2*pos)+2));
}

int lazyUpdate(int *seg, int *lazy, int qlow, int qhigh, int low, int high, int pos, int val)
{
	seg[pos]+=lazy[pos];
	if(low!=high)
	{
		lazy[(2*pos)+1]+=lazy[pos];
		lazy[(2*pos)+2]+=lazy[pos];
	}
	lazy[pos]=0;
	if(qlow<=low && qhigh>=high)
	{
		seg[pos]+=val;
		if(low!=high)
		{
			lazy[(2*pos)+1]+=val;
            		lazy[(2*pos)+2]+=val;
		}
		return seg[pos];
	}
	if(qlow>high || qhigh<low)
	{
		return seg[pos];
	}
	int mid=(low+high)/2;
	seg[pos]=min(lazyUpdate(seg,lazy,qlow,qhigh,low,mid,(2*pos)+1,val),lazyUpdate(seg,lazy,qlow,qhigh,mid+1,high,(2*pos)+2,val));
	return seg[pos];
}

int lazyMin(int *seg, int *lazy, int qlow, int qhigh, int low, int high, int pos)
{
	seg[pos]+=lazy[pos];
	if(low!=high)
	{
		lazy[(2*pos)+1]+=lazy[pos];
		lazy[(2*pos)+2]+=lazy[pos];
	}
	lazy[pos]=0;
	if(qlow<=low && qhigh>=high)
	{
		return seg[pos];
	}
	if(qlow>high || qhigh<low)
	{
		return INT_MAX;
	}
	int mid=(low+high)/2;
	return min(lazyMin(seg,lazy,qlow,qhigh,low,mid,(2*pos)+1),lazyMin(seg,lazy,qlow,qhigh,mid+1,high,(2*pos)+2));
}

int main()
{
	int a[]={6,2,4,3,5,1};
	int n=sizeof(a)/sizeof(int);
	int segSize=(1<<(int)(ceil(log2(n))+1))-1;
	int seg[segSize],lazy[segSize]{0};

	for(int i=0;i<segSize;i++)
		seg[i]=INT_MAX;

	create(a,seg,0,(sizeof(a)/sizeof(int))-1,0);
	for(int i=0;i<segSize;i++)
		cout<<seg[i]<<" ";

	cout<<endl<<rangeMinQuery(seg,0,5,0,n-1,0);

	lazyUpdate(seg,lazy,1,3,0,n-1,0,2);
	cout<<endl;
	for(int i=0;i<segSize;i++)
		cout<<seg[i]<<" ";
	cout<<endl;
	for(int i=0;i<segSize;i++)
		cout<<lazy[i]<<" ";

	lazyUpdate(seg,lazy,3,5,0,n-1,0,4);
	cout<<endl;
	for(int i=0;i<segSize;i++)
		cout<<seg[i]<<" ";
	cout<<endl;
	for(int i=0;i<segSize;i++)
		cout<<lazy[i]<<" ";

	lazyUpdate(seg,lazy,3,5,0,n-1,0,-2);
	cout<<endl;
	for(int i=0;i<segSize;i++)
		cout<<seg[i]<<" ";
	cout<<endl;
	for(int i=0;i<segSize;i++)
		cout<<lazy[i]<<" ";

	cout<<endl<<lazyMin(seg,lazy,4,5,0,n-1,0)<<endl;
	for(int i=0;i<segSize;i++)
		cout<<seg[i]<<" ";
	cout<<endl;
	for(int i=0;i<segSize;i++)
		cout<<lazy[i]<<" ";
	cout<<"\n";
	return 0;
}