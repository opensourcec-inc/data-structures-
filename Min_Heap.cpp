#include<iostream>
using namespace std;

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void insert(int a[], int n)
{
	int temp = a[n], i = n;
	while (i > 1 && temp < a[i / 2])
	{
		a[i] = a[i / 2];
		i /= 2;
	}
	a[i] = temp;
}

void Delete(int a[], int n)
{
	int x = a[1];
	a[1] = a[n];
	int i = 1, j = 2;
	while (j < n)
	{
		if (a[j + 1] < a[j])
			j += 1;
		if (a[i] > a[j])
		{
			swap(&a[i], &a[j]);
			i = j;
			j = 2 * j;
		}
		else
			break;
	}
	a[n] = x;
}

int main()
{
	int a[] = { 0, 10, 20, 30, 25, 5, 40, 35 };
	int n = 7;
	for (int i = 1; i <= n; i++)
		insert(a, i);
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
	for (int i = 1; i <= n; i++)
		Delete(a, n - i + 1);
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	return 0;
}
