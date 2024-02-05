#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100000
 
int N;
int x[MAXN], y[MAXN];
int pos[MAXN], neg[MAXN];
int cid[MAXN];
 
bool cmp(int a,int b)
{
	if(neg[a] == neg[b])
		return pos[a] > pos[b];
	return neg[a] < neg[b];
}
 
int main()
{
	ifstream fin ("mountains.in");
	ofstream fout ("mountains.out");
	fin >> N;
	for(int i=0;i<N;i++)
	{
		fin >> x[i] >> y[i];
		pos[i] = x[i]+y[i], neg[i] = x[i]-y[i];
		cid[i] = i;
	}
	sort(cid,cid+N,cmp);
	int mxpos = -1;
	int ans = 0;
	for(int i=0;i<N;i++)
	{
		if(pos[cid[i]] > mxpos)
		{
			ans++;
			mxpos = pos[cid[i]];
		}
	}
	fout << ans << '\n';
}