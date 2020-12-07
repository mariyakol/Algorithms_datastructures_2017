#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using myPair = pair<int, int>;

void secondTask()
{
	myPair segs;
	vector<myPair> vec;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) 
	{
		cin >> segs.first;
		cin >> segs.second;
		vec.push_back(segs);
	}

	sort(vec.begin(), vec.end(), [](myPair a, myPair b) { return a.first < b.first; });

	int L = 0;
	int l = vec.at(0).first;
	int r = vec.at(0).second;
	int sum = 0;

	for (int i = 1; i < n; ++i)
	{
		if (vec.at(i).first < r+1)
		{
			r = max(r, vec.at(i).second);
		}
		else
		{
			L = L + r - l;
			l = vec.at(i).first;
			r = vec.at(i).second;
		}
	}

	cout << L + r - l << endl;
}

int main()
{
	secondTask();
	return 0;
}