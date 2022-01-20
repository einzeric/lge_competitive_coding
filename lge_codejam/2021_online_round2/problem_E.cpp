#include <bits/stdc++.h>
using namespace std;

int T;
int n;
string cards;

void input()
{
    cin >> cards;
    n = cards.size();
}

void solve()
{
    cout << cards;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        input();
        solve();
    }
    
    return 0;
}