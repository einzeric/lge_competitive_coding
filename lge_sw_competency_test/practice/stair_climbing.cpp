#include <bits/stdc++.h>
using namespace std;

int N;				//	# of stairs
int P[310] = {0};		//	P[i]: score earned when stepping on stair i

int Solve(){
	int sol=0;
	
	int costx = 0;
	int cost0 = P[0];
	int cost1 = P[0] + P[1];
	
	//	TODO : Write your codes.
	for(int i = 2; i<N; i++)
	{
		int cost2 = P[i] + cost0;
		if(cost2 < P[i] + P[i-1] + costx) cost2 = P[i] + P[i-1] + costx;
		costx = cost0;
		cost0 = cost1;
		cost1 = cost2;
	}
	
	sol = cost1;
	return sol;
}

void InputData(){
	cin >> N;
	for(int i=0 ; i<N ; i++){
		cin >> P[i];
	}
}

int main(){
	
	InputData();					//	Input function

	int sol = Solve();

	cout << sol << endl;		//	Answer output
	return 0;
}