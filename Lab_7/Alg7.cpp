#include <fstream>
#include <iostream>
#include <algorithm> 
#include <limits>
#include <vector>
using namespace std;

void seventhTask()
{
	int m;
	cin >> m;
	int * arr = new int[m];
	int k;

	for (int i = 0; i < m; ++i)
	{
		cin >> k;
		arr[i] = k;
	}

	int t = 0;
	int * arr2 = new int[m];
	int * pArr = new int[m];
	int * prevArr = new int[m];
	int l = 0;

	pArr[0] = -1;
	arr2[0] = numeric_limits<int>::min();

	for (int i = 1; i < m; ++i)
	{
		arr2[i] = numeric_limits<int>::max();
	}

	for (int i = 0; i < m; ++i) 
	{
		int l2 = int(upper_bound(arr2, arr2 + m, arr[i]) - arr2);
		int* k = upper_bound(arr2, arr2 + m, arr[i]);
		if (k != arr2 + m)
		{
			if ((arr2[l2-1] < arr[i]) && (arr[i] < arr2[l2]))
			{	
				pArr[l2] = i;
				arr2[l2] = arr[i];
				prevArr[i] = pArr[l2-1];
				l = max(l, l2);
			}
		}
		else
			break;
	}

	vector<int> result;
	t = pArr[l];

	while (t != -1) 
	{
		result.push_back(arr[t]);
		t = prevArr[t];
	}

	reverse(begin(result), end(result));
	cout << result.size() << " ";

	for (auto it : result)
	{
		cout << it << " ";
	}
}

int main() 
{
	seventhTask();
	return 0;
}