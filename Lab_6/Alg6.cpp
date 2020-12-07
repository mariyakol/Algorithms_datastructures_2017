//Cow

#include <iostream>
#include <functional>
#include <fstream>

using namespace std;

int binSearch(int* arr, int left, int right, int inc, std::function<int(int, int)> comp)
{
	int n = (left + right) / 2;

	int res = comp(n, arr[n]);

	if (left < right)
	{
		if (res == 1)
		{
			return binSearch(arr, left, n - inc, inc, comp);
		}
		else if (res == -1)
		{
			return binSearch(arr, n + inc, right, inc, comp);
		}
		else return n;
	}
	else
	{
		return n;
	}
}

int main() {
	
	int c;
	int s;
	cin >> c;
	cin >> s;
	int* K4 = new int[s];

	for (int i = 0; i < s; ++i)
	{
		cin >> K4[i];
	}

	cout << binSearch(K4, 1, (K4[s - 1] - K4[0]), 1, [&K4, c, s](int len, int b)
	{
		int sum = 1;
		int tempK = 0;
		int temp = K4[0];
		for (int j = 1; j < s; ++j)
		{
			tempK = K4[j] - temp;
			if (tempK >= len)
			{
				sum++;
				temp = K4[j];
			}
		}
		if (sum < c)
		{
			return 1;
		}
		else
			if (sum == c)
			{
				int sum2 = 1;
				int tempK2 = 0;
				int temp2 = K4[0];
				for (int j = 1; j < s; ++j)
				{
					tempK2 = K4[j] - temp2;
					if (tempK2 >= (len+1))
					{
						sum2++;
						temp2 = K4[j];
					}
				}
				if (sum2 == c)
				{
					return -1;
				}
				else
					if (sum2 < c)
						return 0;
			}
			else if (sum > c)
			{
				return -1;
			}

	}) << endl;

	return 0;
}