/*You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxArr(vector<int> A) {
    int maxi = INT_MIN;
    int sum[A.size()], diff[A.size()];
    for (int i = 0; i < A.size(); i++)
    {
        sum[i] = A[i] + i;
        diff[i] = A[i] - i;
    }
    
    int max1 = INT_MIN, max2 = INT_MIN, min1= INT_MAX, min2 = INT_MAX;
    
    for (int i = 0; i < A.size(); i++)
    {
        if (sum[i] > max1)
            max1 = sum[i];
            
        if (sum[i] < min1)
            min1 = sum[i];
            
        if (diff[i] > max2)
            max2 = diff[i];
        
        if (diff[i] < min2)
            min2 = diff[i];
    }
    
    int ans1 = abs(max1 - min1);
    int ans2 = abs(max2 - min2);
    
    int ans = ans1 > ans2 ? ans1 : ans2;
    
    return ans;
}

int main()
{
	std::vector<int> v = {1, 3, -1};

	cout << maxArr(v) << endl;
}
