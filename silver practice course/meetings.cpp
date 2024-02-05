#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N,L;
int W[50005],X[50005],D[50005];

struct cow{
  int w,x,d;
  cow(int w0, int x0, int d0){
    w=w0;
    x=x0;
    d=d0;
  }
};

bool operator< (cow a, cow b){
  return a.x<b.x;
}

vector<struct cow>v;
deque<int>timesL,timesR;
int totW;
int T;

void solveT(){
  int indL=0,indR=N-1; //help us add weights of cows from left and right side
  int curW=0;
  for (;;){ //we know at least one is non-empty
    if (timesL.empty() || (!timesR.empty() && timesR[0]<=timesL[0])){ //adding cow from right side
      curW+=v[indR--].w;
      T=timesR[0];
      timesR.pop_front();
    }
    else{ //left side
      curW+=v[indL++].w;
      T=timesL[0];
      timesL.pop_front();
    }
    if (curW*2>=totW)
      break;
  }
  //T will be the last time we checked
}

vector<int>posL,posR;

int getCollisions(){
  int ans=0;
  deque<int>window;
  int ind=0;
  for (int i=0;i<posL.size();i++){
    while (ind<posR.size() && posR[ind]<=posL[i]+T*2){
      window.push_back(posR[ind]);
      ind++;
    }
    while (!window.empty() && window[0]<posL[i])
      window.pop_front();
    ans+=(int)window.size();
  }
  return ans;
}

int main()
{
  freopen ("meetings.in","r",stdin);
  freopen ("meetings.out","w",stdout);
  cin>>N>>L;
  for (int i=0;i<N;i++){
    cin>>W[i]>>X[i]>>D[i];
    totW+=W[i];
    v.push_back(cow(W[i],X[i],D[i]));
    if (D[i]==1)
      timesR.push_back(L-X[i]);
    else
      timesL.push_back(X[i]);
  }
  sort(v.begin(),v.end());
  sort(timesL.begin(),timesL.end());
  sort(timesR.begin(),timesR.end());
  solveT();
  for (int i=0;i<N;i++)
    if (D[i]==1)
      posL.push_back(X[i]);
    else
      posR.push_back(X[i]);
  sort(posL.begin(),posL.end());
  sort(posR.begin(),posR.end());
  cout<<getCollisions()<<endl;
  return 0;
}

