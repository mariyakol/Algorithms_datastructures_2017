//Popular

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using myPair = pair<int, int>;

int comp(myPair a, myPair b)
{
	return a.first < b.first;
}

int main()
{
	myPair segs;
	vector<myPair> vec;
	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> segs.first;
		cin >> segs.second;
		vec.push_back(segs);
	}

	sort(vec.begin(), vec.end(), comp);
	int l = 1;
	int maxI = 0;
	int l2;

	for (int i = 0; i<vec.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (vec.at(i).first <= vec.at(j).second)
			{
				++l;
			}
		}
		if (maxI < l)
		{
			maxI = l;
			l2 = vec.at(i).first;
		}
		l = 1;
	}
	cout << l2 << " " << maxI;

	return 0;
}