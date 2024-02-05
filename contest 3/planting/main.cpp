#include <iostream>
#include <fstream>
using namespace std;
 
int N,a,b;
int d[100000];
 
int main()
{
	ifstream fin("planting.in");
	ofstream fout("planting.out");
	fin >> N;
	for(int i=1;i<N;i++)
	{
		fin >> a >> b;
		d[a-1]++, d[b-1]++;
	}
	int D = 0;
	for(int i=0;i<N;i++)
		if(d[i] > D)
			D = d[i];
	fout << D+1 << '\n';
}