#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N,M;
vector<int>adj[100005];
string S;
bool vis[100005];
int comp[100005],label=1;

void dfs(int node){
  vis[node]=true;
  comp[node]=label;
  for (int x:adj[node])
    if (!vis[x] && S[x]==S[node])
      dfs(x);
}

int main()
{

  cin>>N>>M>>S;
  //for convenience, one-index S
  S='!'+S;
  for (int i=1;i<N;i++){
    int X,Y;
    cin>>X>>Y;
    adj[X].push_back(Y);
    adj[Y].push_back(X);
  }
  for (int i=1;i<=N;i++)
    if (!vis[i]){
      dfs(i);
      label++;
    }
  int A[100005],B[100005];
  char C[100005];
  for (int i=0;i<M;i++)
    cin>>A[i]>>B[i]>>C[i];
  for (int i=0;i<M;i++){
    if (comp[A[i]]==comp[B[i]] && S[A[i]]!=C[i])
      cout<<0;
    else
      cout<<1;
  }
  cout<<endl;
  return 0;
}

