/*
Find the Unique Element

Given an integer array of size 2N + 1. In this given array, N numbers are present twice and one number is present only once in the array.
You need to find and return that number which is unique in the array.
Note : Given array will always contain odd number of elements.

Input format :
Line 1 : Array size i.e. 2N+1
Line 2 : Array elements (separated by space)
Output Format :
Unique element present in the array

Constraints :
1 <= N <= 10^6

Sample Input :
7
2 3 1 6 3 6 2
Sample Output :
1
*/

#include<iostream>
#include <algorithm>

int FindUnique(int arr[], int size){
    int x = 0;
    for (int i = 0; i < size; i++)
    {
        x ^= arr[i];
    }
    return x;
}

using namespace std;

int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	cout<<FindUnique(input,size)<<endl;
		
	return 0;
}
