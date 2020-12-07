#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using myPair = pair<int, int>;

void firstTask()
{
	myPair segs;
	vector<myPair> vec;
	//vector<myPair> vec2;
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) 
	{
		cin >> segs.first;
		cin >> segs.second;
		vec.push_back(segs);
	}

	sort(vec.begin(), vec.end(), [](myPair a, myPair b) { return a.second < b.second; });
	int temp = vec.at(0).second;
	int m = 1;

	//vec2.push_back(vec.at(0));
	for (int i = 1; i < n; ++i)
	{
		if (temp < vec.at(i).first)
		{
			++m;
			temp = vec.at(i).second;
			//vec2.push_back(vec.at(i));
		}
	}
	cout << m << endl;

	/*for (auto it : vec2) //Вывод отрезков
	{
		cout << endl << it.first << " " << it.second;
	}*/
}

int main()
{
	firstTask();
	return 0;
}