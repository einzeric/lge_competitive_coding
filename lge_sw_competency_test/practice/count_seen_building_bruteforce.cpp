#include <iostream>
using namespace std;

int N;//Number of buildings
int a[80010];//Height of buildings

void Input_Data(void){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> a[i];
	}
}

long long solve()
{
	long long sum = 0;
	for(int i = 0; i < N ; i++)
	{
		int j = i+1;
		while(a[i] > a[j] && j++ < N) sum++;
	}
	
	return sum;
}

int main(){
	long long ans = -1;
	Input_Data();		//	Input function

	//	Write the code
	ans = solve();
	
	cout << ans << endl;	//	Output right answer
	return 0;
}