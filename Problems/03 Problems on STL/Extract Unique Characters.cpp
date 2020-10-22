/*
Extract Unique characters

Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.

Input format :
String S
Output format :
Output String

Constraints :
0 <= Length of S <= 10^8

Sample Input 1 :
ababacd
Sample Output 1 :
abcd

Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/

#include <bits/stdc++.h>
using namespace std;

char* uniqueChar(char *str){
    map<char,int> M;
    char* output = new char[10000];
    
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if(M[str[i]] > 0){
            continue;
        }
        else{
            output[k++] = str[i];
            M[str[i]]++;
        }
    }
    output[k] = '\0';
    return output;
}

int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}
