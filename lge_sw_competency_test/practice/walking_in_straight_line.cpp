#include <bits/stdc++.h>
using namespace std;

int N;//Number of employees
int T;//Walking Time (in minutes)
int P[100000 + 10];//Starting location of emplyees
int S[100000 + 10];//Walking speed of emplyees (per minute)

struct emp
{
	int p;
	int s;
};

vector<emp> employees;

bool comp(emp emp1, emp emp2)
{
	return emp1.p > emp2.p;
}

void InputData(){
	cin >> N >> T;
	for (int i = 0; i < N; i++)
	{
		emp tempemp;
		cin >> tempemp.p >> tempemp.s;
		employees.push_back(tempemp);
	}
}

int solve()
{
	int numGroup = 1;
	sort(employees.begin(), employees.end(), comp);
	int maxDist = employees[0].s * T + employees[0].p;
	for(auto it : employees)
	{
		int dist = it.s * T + it.p;
		if(dist < maxDist)
		{
			maxDist = dist;
			numGroup++;
		}
	}
	return numGroup;
}

int main(){
	int ans = -1;

	InputData();			//	Input function

	//	Write the code
	ans = solve();
	
	cout << ans << endl;	//	Output right answer
	return 0;
}
