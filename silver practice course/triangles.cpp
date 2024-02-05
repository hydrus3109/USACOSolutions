#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N,X[100005],Y[100005];
vector<int>vx[20005],vy[20005];
map<pair<int,int>,ll>mpx,mpy;

void solve(int x, int y, vector<int>&v){ 
  int M=v.size();
  ll sum=0;
  //sweep from left to right/down to up
  for (int i=1;i<M;i++)
    sum+=v[i]-v[0];
  for (int i=0;i<M;i++){
    if (x==-1)
      mpx[{v[i],y}]=sum;
    else
      mpy[{x,v[i]}]=sum;
    //update sum during sweep
    if (i+1<M){
      ll diff=v[i+1]-v[i];
      sum+=(i+1)*diff;
      sum-=(M-i-1)*diff;
    }
  }
}

int main()
{

  cin>>N;
  for (int i=0;i<N;i++){
    cin>>X[i]>>Y[i];
    X[i]+=10000;
    Y[i]+=10000;
    vx[X[i]].push_back(Y[i]);
    vy[Y[i]].push_back(X[i]);
  }
  for (int i=0;i<=20000;i++){
    solve(i,-1,vx[i]);
    solve(-1,i,vy[i]);
  }
  //add contribution from each point
  ll ans=0;
  ll MOD=1e9+7;
  for (int i=0;i<N;i++){
    ans+=mpx[{X[i],Y[i]}]*mpy[{X[i],Y[i]}];
    ans%=MOD;
  }
  cout<<ans<<endl;
  return 0;
}

