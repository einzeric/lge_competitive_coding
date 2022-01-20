#include <iostream>
using namespace std;

int N;//Number of mushrooms
int P[150000 + 10] = {0};//Mushroom value

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> P[i];
	}
}

int solve()
{
	int i = 0;
	while(i < N && P[i] < P[i+1]) i++;
	int solution = P[i];
	i++;
	while(i < N)
	{
		while(i < N && P[i] > P[i+1]) i++;
		int j = i + 1;
		while(j < N && P[j] < P[j+1]) j++;
		if(j < N) solution += P[j] - P[i];
		i = j + 1;
	}
	return solution;
}

int main(){
	int ans = -1;

	InputData();			//	Input function

	//	Write the code

	ans = solve();
	
	cout << ans << endl;	//	Output answer
	return 0;
}