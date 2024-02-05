#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
 
int N,M,C;
int t[100000];
 
bool pos(int wait)
{
	int wagons = 1;
	int firstArrival = t[0];
	int firstIndex = 0;
	for(int i=1;i<N;i++)
	{
		if(t[i] - firstArrival > wait || i + 1 - firstIndex > C)
		{
			wagons += 1;
			firstArrival = t[i];
			firstIndex = i;
		}
	}
	return (wagons <= M);
}
 
int binSearch(int low,int high)
{
	if(low == high) return low;
	if(low + 1 == high)
	{
		if(pos(low)) return low;
		return high;
	}
	int mid = (low+high)/2;
	if(pos(mid)) return binSearch(low,mid);
	else return binSearch(mid+1,high);
}
 
int main()
{
	ifstream fin ("convention.in");
	ofstream fout ("convention.out");
	fin >> N >> M >> C;
	for(int i=0;i<N;i++)
		fin >> t[i];
	sort(t,t+N);
	fout << binSearch(0, 1000000000) << '\n';
}