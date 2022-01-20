#include <bits/stdc++.h>
using namespace std;

int N;//roadMap Size
int roadMap[110][110];//roadMap information

struct CELL
{
	int r;
	int c;
	int cost;
};

void Input_Data(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
			scanf("%1d", &roadMap[i][j]);
	}
}

struct comp
{
	bool operator()(const CELL &leftSide, const CELL &rightSide)
	{
		return leftSide.cost > rightSide.cost;
	}
};

int solve()
{
	int solution = 0;
	int adjr[4] = {1,-1,0,0};
	int adjc[4] = {0,0,1,-1};
	
	//Dijkstra to calculate the cheapest path
	int costMap[110][110];
	for(int i = 0; i < N; i++) for (int j = 0; j < N; j++) costMap[i][j]=INT_MAX;
	priority_queue<CELL, vector<CELL>, comp> q;
	CELL source;
	source.r = 0;
	source.c = 0;
	source.cost = roadMap[0][0];
	
	costMap[0][0] = roadMap[0][0];
	q.push(source);
	while(!q.empty())
	{
		CELL currentNode = q.top();
		q.pop();
		int r = currentNode.r;
		int c = currentNode.c;
		int cost = currentNode.cost;
		for(int i=0; i < 4; i++)
		{
			int nextr = r + adjr[i];
			int nextc = c + adjc[i];
			if(nextr < 0 || nextr >=N || nextc < 0 || nextc >=N || costMap[nextr][nextc] <= cost + roadMap[nextr][nextc]) continue;
			
			costMap[nextr][nextc] = cost + roadMap[nextr][nextc];
			CELL next;
			next.r = nextr;
			next.c = nextc;
			next.cost = costMap[nextr][nextc];
			q.push(next);
		}
	}
	
	solution = costMap[N-1][N-1];
	
	return solution;
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int ans = -1;
	Input_Data();		//	Input function


	//	Write the code

	
	printf("%d\n", solve());

	return 0;
}