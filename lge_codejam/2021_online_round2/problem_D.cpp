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
    //Output value
    char digit;
    
    //We try to group numbers which has the same digit count
    //Find the upper and lower bound of the 1st group of number
    //Lower bound of 1st group is always a
    uint64_t lowerBound = a;
    //Number of digit each number in the current group has
    //By converting the number to string, we can quickly get the number of digit
    uint64_t numOfDigit = to_string(lowerBound).size();
    //Upper bound is always in the form of 999..99
    //Starting number of the next group is always 10 to the power of numOfDigit of current group
    //Example: each number in current group has 3 digits. Next group each number has 4 digits
    //Starter of next group is 1000 or 10^3. Minus by 1 and we get end number of current group (999)
    uint64_t upperBound = pow(10, numOfDigit) - 1;
    //Take upperBound, minus lowerBound then divide by step length (b) plus 1 and we get the 
    //count of number in current group
    uint64_t lastTotalNumberCount = 0;
    uint64_t totalNumberCount = (upperBound - a) / b + 1;
    upperBound = a + b * (totalNumberCount - 1);
    uint64_t currentNumberCount = totalNumberCount - lastTotalNumberCount;
    lastTotalNumberCount = totalNumberCount;
    //How many digit this group contributed to the final string
    uint64_t currentDigitCount = currentNumberCount * numOfDigit;
    
    //Repeat until we find which group c belongs to
    while(currentDigitCount < c)
    {
        c -= currentDigitCount;
        lowerBound += b * currentNumberCount;
        numOfDigit++;
        upperBound = pow(10, numOfDigit) - 1;
        totalNumberCount = (upperBound - a) / b + 1;
        upperBound = a + b * (totalNumberCount - 1);
        currentNumberCount = totalNumberCount - lastTotalNumberCount;
        lastTotalNumberCount = totalNumberCount;
        currentDigitCount = currentNumberCount * numOfDigit;
    }
    //Figure out which number in current group c belongs to
    uint64_t numPos = (c / numOfDigit) - ((c % numOfDigit) == 0);
    //Calculate that number
    uint64_t numC = lowerBound + b * numPos;
    //Calculate position of cth digit in that number
    c = c - numPos * numOfDigit - 1;
    //Convert number to string and extract digit
    string s = to_string(numC);
    digit = s[c];
    cout << digit << '\n';
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