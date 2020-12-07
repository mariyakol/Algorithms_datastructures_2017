#include <iostream>
#include <functional>
#include <vector>
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
			return binSearch(arr, n + 1, right, inc, comp);
		}
		else return n;
	}
	else
	{
		return n;
	}
}

int main() {
	int m;
	cin >> m;
	int* A = new int[m];
	int* B = new int[m];
	for (int i = 0; i < m; ++i)
	{
		cin >> A[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> B[i];
	}
	cout << binSearch(A, 0, m-1, 0, [&B, m](int n, int An)
	{
		if (An < B[n]) {
			if (m == (n + 1))
			{
				return 0;
			}
			else
				return -1;
		}
		else
			if (An > B[n]) return 1;
			else
				if (An == B[n]) return 0;
	}
	);
	return 0;
}