#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N,K,M;

bool check(ll X){ 
  //simulate days until <= M per day
  ll daysPassed=0,G=0;
  while (daysPassed<K && G<N){ //or if this condition breaks first
    ll Y=(N-G)/X;
    if (Y<=M)
      break;
    //how many days of Y will follow?
    //do some math
    ll daysToAdd=(N-G-X*Y)/Y+1;
    daysToAdd=min(daysToAdd,K-daysPassed);
    G+=Y*daysToAdd;
    daysPassed+=daysToAdd;
  }
  G+=(K-daysPassed)*M;
  
  return G>=N;
}

int main()
{

  cin>>N>>K>>M;
  ll low=0,high=N+1;
  while (low+1<high){
    ll mid=(low+high)/2;
    if (check(mid))
      low=mid;
    else
      high=mid;
  }
  cout<<low<<endl;
  return 0;
}

