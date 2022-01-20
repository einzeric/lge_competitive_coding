#include <bits/stdc++.h>
using namespace std;

int T;
int digits[11] = {0};

void input()
{
    for(int i = 1; i < 10; i++)
    {
        cin >> digits[i];
    }
    digits[9] += digits[6];
    digits[6] = 0;
}

void solve()
{
    vector<int> leftSide;
    stack<int> rightSide;
    bool goLeft = true;
    for(int i = 9; i > 0; i--)
    {
        for(int j = 0; j < digits[i]; j++)
        {
            if(goLeft)
            {
                leftSide.push_back(i);
            }
            else
            {
                rightSide.push(i);
            }
            goLeft = !goLeft;
        }
    }
    
    for(auto it : leftSide)
    {
        cout << it << ' ';
    }
    while(!rightSide.empty())
    {
        cout << rightSide.top() << ' ';
        rightSide.pop();
    }
    cout << '\n';
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