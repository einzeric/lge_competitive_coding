#include <bits/stdc++.h>
using namespace std;

int T;
uint64_t a,b,c;

void input()
{
    cin >> a >> b >> c;
}

void solve()
{
    char digit;
    uint64_t i = 0;
    string s = to_string(a + b*i);
    uint64_t sLength = s.size();
    while(c > sLength)
    {
        c -= sLength;
        i++;
        string s = to_string(a + b*i);
        sLength = s.size();
    }
    digit = s[c-1];
    cout << digit << '\n';
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        input();
        solve();
    }
    
    return 0;
}