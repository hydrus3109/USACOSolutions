#include <bits/stdc++.h>
#include <fstream>
using namespace std;

typedef vector<int> vi; 
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back
 
vi stor; // first 8 numbers
 
bool ok(int x) { return x%3 && x%5; } // not fizz or buzz
int dumb(int N) { // get f(n) slowly
	for (int i = 1;;++i) if (ok(i)) {
		N --;
		if (N == 0) return i;
	}
}
int smart(int N) { // get f(n) quickly
	int num = (N-1)/8;
	return stor[N-8*num-1]+15*num;
}
 
int main() {
	ifstream fin ("moobuzz.in");
	ofstream fout ("moobuzz.out");
	FOR(i,1,16) if (ok(i)) stor.pb(i);
	int N; fin >> N;
	fout << smart(N) << "\n";
}