
#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
#define pb push_back
using namespace std;
const int ha=1000000007;
vector<int> g[maxn];
int f[maxn][4],col[maxn];
int n,m,k,ans;
 
inline int add(int x,int y){
    x+=y;
    if(x>=ha) return x-ha;
    else return x;
}
 
void dfs(int x,int fa){
    f[x][1]=f[x][2]=f[x][3]=1;
    
    int to,tmp;
    for(int i=g[x].size()-1;i>=0;i--){
        to=g[x][i];
        if(to==fa) continue;
        
        dfs(to,x);
        
        tmp=add(f[to][1],add(f[to][2],f[to][3]));
        for(int j=1;j<=3;j++) f[x][j]=f[x][j]*(ll)add(tmp,ha-f[to][j])%ha;
    }
    
    if(col[x]){
        for(int i=1;i<=3;i++) if(i!=col[x]) f[x][i]=0;
    }
}
 
int main(){
    int uu,vv;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        scanf("%d%d",&uu,&vv);
        g[uu].pb(vv),g[vv].pb(uu);
    }
    for(int i=1;i<=k;i++){
        scanf("%d%d",&uu,&vv);
        col[uu]=vv;
    }
    
    dfs(1,0);
    
    ans=add(add(f[1][2],f[1][1]),f[1][3]);
    printf("%d\n",ans);
    
    return 0;
}