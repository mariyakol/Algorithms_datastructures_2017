#include <vector>
#include <iostream>

using namespace std;

using vecP = vector<vector<int>>;

int countRoute(int k, int n, vecP* vec)
{
	if ((k == 1) && (n == 1))
	{
		vec->at(0).at(0) = 1;
		return 1;
	}
	else
		if (k == 1)
		{
			if (vec->at(k - 1).at(n - 1) == 0)
			{
				vec->at(k - 1).at(n - 1) = countRoute(k, n - 1, vec);
				return vec->at(k - 1).at(n - 1);
			}
			else
				return vec->at(k - 1).at(n - 1);
		}
		else
			if (n == 1)
			{
				if (vec->at(k - 1).at(n - 1) == 0)
				{
					vec->at(k - 1).at(n - 1) = countRoute(k - 1, n, vec);
					return vec->at(k - 1).at(n - 1);
				}
				else
					return vec->at(k - 1).at(n - 1);
			}
			else
			{
				if (vec->at(k - 1).at(n - 1) == 0)
				{
					vec->at(k - 1).at(n - 1) = countRoute(k, n - 1, vec) + countRoute(k - 1, n - 1, vec) + countRoute(k - 1, n, vec);
					return vec->at(k - 1).at(n - 1);
				}
				else
					return vec->at(k - 1).at(n - 1);
			}
}

int main()
{
	int m, n;
	cin >> m;
	cin >> n;
	vecP vec = vecP(m, vector<int>(n));
	cout << countRoute(m, n, &vec) << endl;
	return 0;
}