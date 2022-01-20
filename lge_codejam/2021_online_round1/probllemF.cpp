#include <bits/stdc++.h>
using namespace std;

int t, n, q;
int32_t v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		map<int32_t, int32_t> m;
		cin >> n >> q;
		for(int j = 0; j < n; j++)
		{
			int d;
			cin >> d;
			m[d]++;
		}
		
		for(int j = 0; j < q; j++)
		{
			int o;
			int32_t prevMin, prevMax, prevMinV = -1, prevMaxV = -1;
			switch(o)
			{
				case 1:
				{
					cin >> v;
					if(v == prevMinV)
					{
						cout << prevMin;
					}
					else
					{
						int32_t min = INT_MAX;
						for(auto it : m)
						{
							int32_t temp = v^it.first;
							if(min > temp) min = temp;
						}
						cout << min << '\n';
						prevMin = min;
						prevMinV = v;
					}
					break;
				}
				case 2:
				{
					cin >> v;
					if(v == prevMaxV)
					{
						cout << prevMax;
					}
					else
					{
						int32_t max = -1;
						for(auto it : m)
						{
							int32_t temp = v^it.first;
							if(max < temp) max = temp;
						}
						cout << max << '\n';
						prevMax = max;
						prevMaxV = v;
					}
					break;
				}
				case 3:
				{
					cin >> v;
					if(m.find(v) == m.end())
					{
						m[v]++;
						prevMinV = -1;
						prevMaxV = -1;
					}
					cout << m.size() << '\n';
					break;
				}
				case 4:
				{
					cout << m.begin()->first << '\n';
					m.erase(m.begin());
					break;
				}
				case 5:
				{
					auto it = m.end();
					it--;
					cout << it->first << '\n';
					m.erase(it);
					break;
				}
			}
		}
	}
	
	return 0;
}