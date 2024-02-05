#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define PB push_back
#define MP make_pair
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
  ll n, A, B;
  scanf("%lld %lld %lld", &n, &A, &B);
  vector<pll> V;
  for(ll i=0; i<n; i++) {
    char buf[100];
    ll w;
    scanf("%s %lld", buf, &w);
    V.PB(MP(w, buf[0]=='S' ? 1 : 0));
  }
  ll INF = ll(1000)*1000*1000*1000;
  V.PB(MP(-INF, 0));
  V.PB(MP(INF, 0));
  sort(V.begin(), V.end());

  ll ans = 0;
  for(ll i=0; i+1<V.size(); i++) {
    ll S = V[i].X;
    ll E = V[i+1].X;
    ll M = (S+E)/2;

    if(V[i].Y==1) {
      ll s = max(A, S+1);
      ll e = min(B, M);
      if(e >= s) {
        ans += e-s+1;
      }
    }
    if(V[i+1].Y==1) {
      ll s = max(A, M+1);
      ll e = min(B, E);
      if(e >= s) {
        ans += e-s+1;
      }
    }
    if(V[i+1].Y==1 && V[i].Y==0 && (S%2)==(E%2) && A<=M && M<=B) {
      ans++; // Should count M
    }
  }
  printf("%lld\n", ans);
}