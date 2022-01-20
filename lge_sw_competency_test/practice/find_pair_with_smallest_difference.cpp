#include <bits/stdc++.h>
using namespace std;

int N;//The number of candidates
int A[100000 + 10];//Temperament value

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
}

void solve()
{
	int i = 0;
	int j = N-1;
	int min = INT_MAX;
	int subj1 = i;
	int subj2 = j;
	int diff = INT_MAX;
	while(i < j)
	{
		if(abs(A[i] + A[j]) < diff)
		{
			diff = abs(A[i] + A[j]);
			j--;
		}
		else
		{
			j++;
			if(min > diff)
			{
				min = diff;
				subj1 = i;
				subj2 = j;
			}
			i++;
			diff = INT_MAX;
		}
	}
	
	cout << subj1 << " " << subj2;
}

int main(){
    InputData();//	Input function

	//	Create the code
	solve();
	
    return 0;
}