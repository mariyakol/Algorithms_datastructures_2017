#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int secondTask(string str, int** arr, int i, int j) {
	if (arr[i][j] == -1)
	{
		if (str[i] == str[j])
		{
			arr[i][j] = secondTask(str, arr, i + 1, j - 1) + 2;
		}
		else
		{
			arr[i][j] = max(secondTask(str, arr, i + 1, j), secondTask(str, arr, i, j - 1));
		}
	}
	return arr[i][j];
}

int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	int ** arr = new int*[n];

	for (int i = 0; i < n; ++i)
	{
		arr[i] = new int[n];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) 
		{
			if (i == j)
				arr[i][j] = 1;
			else
				if (i < j)
					arr[i][j] = -1;
				else
					arr[i][j] = 0;
		}
	}

	int m = secondTask(str, arr, 0, str.length() - 1);
	cout << m << " ";

	string res(m, ' ');
	int i = 0;
	int j = str.length() - 1;
	int palL = 0;
	int palR = m - 1;

	while (i <= j)
	{
		if (i == j && arr[i][j] == 1)
			res[palL++] = str[i++];
		else
			if (str[i] == str[j])
			{
				res[palL++] = str[i++];
				res[palR--] = str[j--];
			}
			else
				if (arr[i + 1][j] > arr[i][j - 1])
					i++;
				else
					j--;
	}

	cout << res;
	return 0;
}