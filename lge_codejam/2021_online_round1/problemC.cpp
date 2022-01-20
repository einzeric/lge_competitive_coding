#include <bits/stdc++.h>
using namespace std;

int t, n;
// int32_t a[100001];
// string str2020 = "2020";

int solve(const unordered_map<int,int> &m)
{
	int count = 0;
	for(auto it = m.begin(); it != m.end(); it++)
	{
		for(auto jt = it; jt != m.end(); jt++)
		{
			int32_t sum = it->first + jt->first;
			if(2021 == sum % 10000)
			{
				while(sum > 2020) sum /= 10;
				int pair = 0;
				if(2020 == sum)
					if(it == jt)
						pair = it->second * (it->second - 1);
					else
						pair = it->second * jt->second;
				count += pair;
			}
		}
	}
	
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		unordered_map<int,int> m;
		for(int j = 0; j < n; j++)
		{
			int d;
			cin >> d;
			m[d]++;
		}
		cout << solve(m) <<'\n';
	}
	
	return 0;
}