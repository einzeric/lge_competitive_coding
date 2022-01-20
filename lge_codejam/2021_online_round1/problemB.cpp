#include <bits/stdc++.h>

using namespace std;

int t, n;
priority_queue<int> q;


uint64_t solve()
{
	uint64_t product = 0;
	uint64_t a = 0;
	uint64_t b = 0;
	while(!q.empty())
	{
		//insert digit to the right of lesser number
		if(a < b) a = 10*a + q.top();
		else b = 10*b + q.top();
		q.pop();
	}
	product = a*b;
	
	return product;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	cin.get();
	for(int i = 0; i < t; i++)
	{
		string s;
		getline(cin, s);
		for(auto c : s)
		{
			int d = c-48;
			d += 3 * (6 == d);
			q.push(d);
		}
		cout <<  solve() << "\n";
	}
}