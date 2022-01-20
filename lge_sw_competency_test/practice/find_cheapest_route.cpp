#include <bits/stdc++.h>
using namespace std;
int H;//Height
int W;//Width
char road[500][510];//map

void input_data(){
	int i;
	cin >> H >> W;
	for(i=0 ; i<H ; i++)
	{
		cin >> road[i];
	}
}

struct node
{
	node(int R, int C, int DIST) : r(R), c(C), dist(DIST) {}
	int r, c, dist;
};

bool comp(const node &a, const node&b)
{
	return a.dist > b.dist;
}

int solve()
{
	int min_dist = INT_MAX;
	int adj_r[4] = {1,-1,0,0};
	int adj_c[4] = {0,0,1,-1};
	int distMap[500][510];
	for(int r = 0; r < H; r++)
		for(int c = 0; c < W; c++)
			distMap[r][c] = INT_MAX;
	distMap[0][0] = 0;
	
	priority_queue<node, vector<node>, decltype(&comp)> q(comp);
	node first(0,0,0);
	q.push(first);
	while(!q.empty())
	{
		node current  = q.top();
		q.pop();
		int r = current.r;
		int c = current.c;
		int dist = current.dist;
		for(int i = 0; i < 4; i++)
		{
			int next_r = r + adj_r[i];
			int next_c = c + adj_c[i];
			if(next_r >= H || next_r < 0 || next_c >= W || next_c < 0 || road[next_r][next_c] == 'X' || distMap[next_r][next_c] <= dist + 1) continue;
			
			distMap[next_r][next_c] = dist+1;
			node next(next_r, next_c, distMap[next_r][next_c]);
			q.push(next);
		}
	}
	min_dist = distMap[H-1][W-1];
	
	return (distMap[H-1][W-1] == INT_MAX ? -1 : min_dist);
}

int main()
{
	int ans = 0;
	input_data();
	
	// auto start = chrono::high_resolution_clock::now();
	ans = solve();
	// auto end = chrono::high_resolution_clock::now();
	// auto diff = end - start;
	// cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
	
	cout << ans << endl;
	return 0;
}