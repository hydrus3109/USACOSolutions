#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define f first 
#define s second


const int N = 752, M=1e9+7;
int tt=1,n,k,R,C,a[N][N];


	template<class T> struct Seg {
	const T ID = 0; T comb(T a, T b){ return (a+b+M)%M; }

	int n=0; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }

	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) {
		seg[p += n] += val; seg[p] %= M; for (p /= 2; p; p /= 2) pull(p); }

	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};


ll q[N];

int main(){

// cin>>tt;
while(tt--){

	 cin >> R >> C >> k;

	 Seg<ll> c[k+3],b;
	 map<int,int> m[k+3];	 
	 vector<int> v[k+3];
	 b.init(C+1);

	 for(int i=1; i<=R; i++)
	 	 for(int j=1; j<=C; j++){
	 	 	 cin >> a[i][j];
	 	 	 v[a[i][j]].push_back(j);
	 	 }

	 for(int i=1; i<=k; i++){
	 	 sort(v[i].begin(), v[i].end());
	 	 for(int x : v[i])
	 	 	 if(!m[i][x])
	 	 	 	 m[i][x] = m[i].size();
	 }

	 for(int i=1; i<=k; i++)
	 	 c[i].init(m[i].size()+2);
	 

	 b.upd(1,1);
	 c[a[1][1]].upd(m[a[1][1]][1],1);

	 for(int i=2; i<=R; i++){

	 	 for(int j=2; j<=C; j++){
	 	 	 int x = a[i][j];
	 	 	 q[j] = b.query(1,j-1) - c[x].query(1, m[x][j]-1) + M;
	 	 	 q[j] %= M;
	 	 }
	 	 for(int j=2; j<=C; j++){
	 	 	 int x = a[i][j]; 	
	 	 	 b.upd(j, q[j]);
	 	 	 c[x].upd(m[x][j], q[j]);
	 	 }
	 }
	 cout << q[C];
 }
   return 0; 
}
