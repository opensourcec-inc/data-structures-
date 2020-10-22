/*
Longest Consecutive Sequence

You are given an array of unique integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.

Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :
0 <= n <= 10^8

Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 

Sample Output 1 :
8 
9 
10 
11 
12

Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7
8
9

Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but output should be [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array.

Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 
16
*/

#include<bits/stdc++.h>
using namespace std;

int getIndex(int *arr, int n, int x){
    int index = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == x){
            index = i;
            break;
        }
    }
    return index;
}

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
    map<int,bool> M;
    for(int i = 0; i < n; i++)
        M[arr[i]] = true;
    
    int max_length = 0;
    int start = 0;
    for(int i = 0; i < n; i++){
        if(M[arr[i]] == true){
            int length = 1;
            int x = arr[i]+1;
            int curr_start = arr[i];
            while(M[x] == true){
                length++;
                M[x] = false;
                x++;
            }
            x = arr[i]-1;

            while(M[x] == true){
                length++;
                curr_start = x;
                M[x] = false;
                x--;
            }
            if(length > max_length){
                max_length = length;
                start = curr_start;
            }
            else if(length == max_length){
                int a = getIndex(arr,n,curr_start);
                int b = getIndex(arr,n,start);
                if(a < b){
                    start = curr_start;
                }
            }
        }
    }

    vector<int> result(max_length);
    for (int i = 0; i < max_length; i++)
    {
        result[i] = start+i;
    }
    
    return result;
}

int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);
  
  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it << endl;
  }

  delete arr;
}