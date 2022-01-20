#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int N,M;
int map[51][51];
int r_1stCell = 0, c_1stCell = 0; //coordinate of the 1st cell found on 1st island

void clearQueue(queue<pair<int,int>> &q)
{
	queue<pair<int,int>> emptyQueue;
	q.swap(emptyQueue);
}

int solve()
{
	int solution = 9999;
	
	//BFS to find all cells of 1st island
	vector<pair<int,int>> first_island_cells;
	queue<pair<int, int>> q;
	int visited[51][51] = {0};
	q.push({r_1stCell, c_1stCell});
	while(!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		if(1 == visited[r][c])
		{
			q.pop();
			continue;
		}
		if(1 == map[r][c])
		{
			map[r][c] = 2;
			first_island_cells.push_back({r, c});
			if(r+1 < N) if(0 == visited[r+1][c]) q.push({r+1, c});
			if(c+1 < M) if(0 == visited[r][c+1]) q.push({r, c+1});
			if(r-1 >= 0) if(0 == visited[r-1][c]) q.push({r-1, c});
			if(c-1 >= 0) if(0 == visited[r][c-1]) q.push({r, c-1});
		}
		q.pop();
		visited[r][c] = 1;
	}
	
	//BFS to find a shortest path from 1st island to 2nd island
	for(auto it : first_island_cells)
	{
		clearQueue(q);
		memset(visited, 0, sizeof visited);
		if(1 == map[it.first + 1][it.second] &&
		   1 == map[it.first][it.second + 1] &&
		   1 == map[it.first - 1][it.second] &&
		   1 == map[it.first][it.second - 1]) continue;
		int currentMinDistance = 9999;
		
		q.push({it.first, it.second});
		while(!q.empty())
		{
			int r = q.front().first;
			int c = q.front().second;
			if(1 == visited[r][c])
			{
				q.pop();
				continue;
			}
			
			if (1 == map[r][c])
			{
				currentMinDistance = abs(r - it.first) + abs(c - it.second) - 1;
				if(currentMinDistance < solution) solution = currentMinDistance;
			}
			else
			{
				currentMinDistance++;
				if(r+1 < N) if(0 == visited[r+1][c]) q.push({r+1, c});
				if(c+1 < M) if(0 == visited[r][c+1]) q.push({r, c+1});
				if(r-1 >= 0) if(0 == visited[r-1][c]) q.push({r-1, c});
				if(c-1 >= 0) if(0 == visited[r][c-1]) q.push({r, c-1});
			}
			q.pop();
			visited[r][c] = 1;
		}
	}
	return solution;
}


int main()
{
	cin >> N;
	cin >> M;
	bool found1stIsland = false;
	for(int r = 0; r < N; r++)
		for(int c = 0; c < M; c++)
		{
			cin >> map[r][c];
			if(!found1stIsland) if(1 == map[r][c])
			{
				r_1stCell = r;
				c_1stCell = c;
			}
		}
	
	cout << solve();
	return 0;
}