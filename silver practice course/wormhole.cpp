#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N,M;
int P[100005];
int A[100005],B[100005],W[100005];
vector<int>adj[100005];

bool perfectSort(){
  for (int i=1;i<=N;i++)
    if (P[i]!=i)
      return false;
  return true;
}

bool vis[100005];
vector<int>v1,v2;

void dfs(int node){
  vis[node]=true;
  v1.push_back(node);
  v2.push_back(P[node]);
  for (int x:adj[node])
    if (!vis[x])
      dfs(x);
}

bool check(ll minW){
  for (int i=1;i<=N;i++){
    adj[i].clear();
    vis[i]=false;
  }
  for (int i=0;i<M;i++)
    if (W[i]>=minW){
      adj[A[i]].push_back(B[i]);
      adj[B[i]].push_back(A[i]);
    }
  for (int i=1;i<=N;i++){
    if (!vis[i]){
      v1.clear();
      v2.clear();
      dfs(i);
      sort(v1.begin(),v1.end());
      sort(v2.begin(),v2.end());
      if (v1!=v2)
	return false;
    }
  }
  return true;
}

int main()
{

  cin>>N>>M;
  for (int i=1;i<=N;i++)
    cin>>P[i];
  if (perfectSort()){
    cout<<-1<<endl;
    return 0;
  }
  for (int i=0;i<M;i++)
    cin>>A[i]>>B[i]>>W[i];
  ll low=0,high=1e9+1;
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

