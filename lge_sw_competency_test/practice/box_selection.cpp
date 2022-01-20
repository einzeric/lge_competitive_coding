#include <iostream>
using namespace std;

int N;//The number of goods to send 
int C[10];//The number of BOXes(in order of 1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000)
int sol[10];//The number of boxes to send
int box[10] = {1,5,10,50,100,500,1000,3000,6000,12000};

void InputData(){
	int i;
	cin >> N;
	for(i = 0; i < 10; i++){
		cin >> C[i];
	}
}

void OutputData()
{
	int ans = 0;
	for(int i = 0; i < 10; i++) ans += sol[i];
	cout << ans << endl;
	for(int i = 0; i < 10; i++)
	{
		cout << sol[i] << " ";
	}
	cout << endl;
}

void solve()
{
	int remain = N;
	while(remain > 0)
	{
		int sum = 0;
		for(int i = 0; i < 9; i++)
		{
			if(sum + box[i]*C[i] < remain)
			{
				sum += box[i]*C[i];
			}
			else
			{
				int j = 1;
				while(sum + box[i] * j < remain) j++;
				sol[i] = j;
				remain -= box[i]*j;
				// cout << "sum=" << sum << " j=" << j << " remain=" << remain << '\n';
				break;
			}
		}
	}
}

int main(){
	int ans = -1;

	InputData();//	Input function
    
	//	Create the code
	solve();

	OutputData();//	Output function

	return 0;
}