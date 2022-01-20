#include <bits/stdc++.h>

using namespace std;

int t;
int l;
string s;

map<char, tuple<int,int,int>> keyboard = 
{
	{'Q', {0, 0, 0}},
	{'W', {0, 1, 1}},
	{'E', {0, 2, 2}},
	{'R', {0, 3, 3}},
	{'T', {0, 4, 4}},
	{'Y', {0, 5, 5}},
	{'U', {0, 6, 6}},
	{'I', {0, 7, 7}},
	{'O', {0, 8, 8}},
	{'P', {0, 9, 9}},
	{'A', {1, 0, 1}},
	{'S', {1, 1, 2}},
	{'D', {1, 2, 3}},
	{'F', {1, 3, 4}},
	{'G', {1, 4, 5}},
	{'H', {1, 5, 6}},
	{'J', {1, 6, 7}},
	{'K', {1, 7, 8}},
	{'L', {1, 8, 9}},
	{'Z', {2, 0, 2}},
	{'X', {2, 1, 3}},
	{'C', {2, 2, 4}},
	{'V', {2, 3, 5}},
	{'B', {2, 4, 6}},
	{'N', {2, 5, 7}},
	{'M', {2, 6, 8}}
};

int solve()
{
	int solution = 0;
	char lastK = s[0];
	for(auto k : s)
	{
		//first, calculate distance from last key to current key
		int dist = 0;
		if(k == lastK) dist = 0; //if same key then distance = 0
		else //otherwise calculate distance based on keyboard coordinate
		{
			dist = abs(get<0>(keyboard[k]) - get<0>(keyboard[lastK])) +
					abs(get<1>(keyboard[k]) - get<1>(keyboard[lastK])) +
					abs(get<2>(keyboard[k]) - get<2>(keyboard[lastK]));
		}
		solution += 1 + dist;
		lastK = k;
	}
	
	return solution;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	cin.get();
	for(int i = 0; i < t; i++)
	{
		getline(cin, s);
		cout << solve() << "\n";
	}
	
	return 0;
}