#include <iostream>
using namespace std;

int N;
int paper[12][12];
int color[10] = {0};

void solve()
{
	for(int currentColor = 1; currentColor <= 9; currentColor++)
	{
		int currColorLeft = 99;
		int currColorRight = -1;
		int currColorTop = 99;
		int currColorBot = -1;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if(paper[i][j] == currentColor)
				{
					if(currColorLeft > j) currColorLeft = j;
					if(currColorRight < j) currColorRight = j;
					if(currColorTop > i) currColorTop = i;
					if(currColorBot < i) currColorBot = i;
				}
			}
		}
		if(99 != currColorLeft) color[currentColor]++;
		
		for(int i = currColorTop; i <= currColorBot; i++)
		{
			for(int j = currColorLeft; j <= currColorRight; j++)
			{
				if(paper[i][j] != currentColor)
				{
					color[paper[i][j]]++;
				}
			}
		}
	}
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			scanf("%1d", &paper[i][j]);
		}
	}
	solve();
	int solution = 0;
	for(int i = 1; i <= 9; i++)
	{
		if(color[i] == 1) solution++;
	}
	cout << solution;
}