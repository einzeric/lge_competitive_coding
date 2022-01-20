#include <bits/stdc++.h>
using namespace std;

int T;
int n;
uint64_t x;
uint64_t v[100001] = {0};

void input()
{
    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
}

void solve()
{
    uint64_t count = 0;
    unordered_map<uint64_t,int> countV;
    for(int i = 0; i < n; i++)
    {
        uint64_t other = x ^ v[i];
        if(countV.find(other) != countV.end())
        {
            count += countV[other];
        }
        countV[v[i]]++;
    }
    
    cout << count << "\n";
}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        input();
        solve();
    }
    
    return 0;
}