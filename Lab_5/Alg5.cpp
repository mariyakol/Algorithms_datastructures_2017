#include <iostream>
#include <functional>
#include <fstream>
#include <algorithm>

using namespace std;

using F = int(int, int);

int binSearch(int* arr, int left, int right, int inc, function<F> comp)
{
	int m = (left + right) / 2;

	int result = comp(m, arr[m]);

	if (left < right)
	{
		if (result == 1)
		{
			return binSearch(arr, left, m - inc, inc, comp);
		}
		else if (result == -1)
		{
			return binSearch(arr, m + inc, right, inc, comp);
		}
		else return m;
	}
	else if (result != 0)
	{
		return -1;
	}
	else
	{
		return m;
	}
}

int main() 
{
	int m, d;
	cin >> m;
	cin >> d;	
	int* lenArr = new int[m];
	for (int i = 0; i < m; ++i)
	{
		cin >> lenArr[i];
	}
	sort(lenArr, lenArr + m, [](int a, int b) {return a < b; });
	cout << binSearch(lenArr, 1, lenArr[m-1], 1, [&d, &lenArr, m](int c, int nothing)
	{
		int n = 0;
		for (int i = 0; i < m; ++i)
		{
			n += lenArr[i] / c;
		}
		if (n < d)
			return 1;
		else
			if (n > d)
			{
				n = 0;
				for (int i = 0; i < m; ++i)
				{
					n += lenArr[i] / (c + 1);
				}
				if (n < d)
					return 0;
				else
					return -1;
			}
			else
				if (n == d)
					return 0;
	});
	return 0;
}