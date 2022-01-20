#include <bits/stdc++.h>
using namespace std;

int T;
uint64_t n, x;

void input(unordered_map<uint64_t,uint64_t>& v)
{
    cin >> n >> x;
    for(uint64_t i = 0; i < n; i++)
    {
        uint64_t d;
        cin >> d;
        v[d]++;
    }
}

void solve(unordered_map<uint64_t,uint64_t>& v)
{
    uint64_t count = 0;
    for(auto it : v)
    {
        uint64_t other = x ^ (it.first);
        if(v.count(other) > 0)
        {
            if(it.first == other)
            {
                count += (it.second * (it.second -1)) >> 1;
            }
            else
            {
                count += (it.second * v[other]);
                v.erase(other);
            }
        }
    }
    
    cout << count << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        unordered_map<uint64_t,uint64_t> v;
        input(v);
        solve(v);
    }
    
    return 0;
}