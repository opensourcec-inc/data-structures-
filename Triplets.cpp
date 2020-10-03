/*Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.*/

#include <iostream>
#include <vector>

using namespace std;

int solve(vector<string> A) {
    vector<float> B;
    for (int i = 0; i < A.size(); i++)
    {
        if (stof(A[i]) < 2)
            B.push_back(stof(A[i]));
    }
    
    float a = B[0], b = B[1], c = B[2];
    
    for (int i = 3; i < B.size(); i++)
    {
        if (1 < a+b+c && a+b+c < 2)
            return true;
            
        else if (a+b+c > 2)
        {
            if (a > b && a > c && a > B[i])
                a = B[i];
                
            else if (b > a && b > c && b > B[i])
                b = B[i];
                
            else if (c > a && c > b && c > B[i])
                c = B[i];
        }
        
        else
        {
            if (a < b && a < c && a < B[i])
                a = B[i];
                
            else if (b < a && b < c && b < B[i])
                b = B[i];
                
            else if (c < a && c < b && c < B[i])
                c = B[i];
        }
    }
    
    if (a + b + c > 1 && a + b + c < 2)
        return 1;
    else
        return 0;
}

int main()
{
	std::vector<string> v = {"0.6", "0.7", "0.8", "1.2", "0.4"};

	cout << solve(v) << endl;
}
