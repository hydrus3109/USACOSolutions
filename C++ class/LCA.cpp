#include<iostream> //AC LCA (Tarjan) 
#include<vector> 
#include<queue>
#define MAX 10010 
using namespace std; 
int n,flag; 
int f[MAX],r[MAX],ancestor[MAX]; 
int indegree[MAX],vis[MAX];
int dist[MAX],layer[MAX];
vector<pair<int,int>> head[MAX],Que[MAX]; 

queue<pair<int,int>> que;
void bfs(){
    pair<int,int> begin;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            begin = make_pair(i,0);
        }
    }
    que.push(begin);
    int layer1 = 0;
    layer[begin.first] = 0;
    dist[begin.first] = 0;
    while(que.empty() == 0){
        pair<int,int> cur = que.front();
        que.pop();
        int node = cur.first;
        vector<pair<int,int>> temp = Que[node];
        for(int i = 0; i < temp.size(); i++){
            pair<int,int> temp1 = temp[i];
            temp1.second += cur.second;
            dist[temp1.first] = temp1.second;
            layer[temp1.first] = layer1;
            que.push(temp1);
        }
        layer1++;
    }
   
}
void Init(){
     int i,a,b,c; 
     cin>>n; 
     flag=0; 
     for(i=1;i<=n;i++){ 
        head[i].clear(); 
        Que[i].clear(); 
        f[i]=i; 
        r[i]=1; 
        ancestor[i]=0; 
        indegree[i]=0; 
        vis[i]=0; 
        } 
        for(i=1;i<n;i++){ 
            cin>>a>>b >> c; head[a].push_back({b,c}); indegree[b]++; 
            } 
            cin>>a>>b; 
            Que[a].push_back({b,c}); 
            Que[b].push_back({a,c}); 
        }
        
 int Find(int u){ 
    if(f[u]==u) 
        return f[u]; 
    else 
        f[u]=Find(f[u]); 
    return f[u]; 
} 
void Union(int v,int u) { 
    int a,b; 
    a=Find(v); 
    b=Find(u); 
    if(a==b) 
        return; 
    if(r[a]<=r[b]) { 
        f[a]=b; r[b]+=r[a]; 
    } 
    else { f[b]=a; r[a]+=r[b]; } 
} 
void LCA(int k) { 
    int i,size; 
    size=head[k].size(); 
    ancestor[k]=k; 
    for(i=0;i<size;i++) { 
        if(flag) break; 
        LCA(head[k][i].first);
        Union(k,head[k][i].first); 
        ancestor[Find(k)]=k; 
    } 
    vis[k]=1; size=Que[k].size(); 
    for(i=0;i<size;i++) { 
        if(vis[Que[k][i].first]){ 
            flag=1; 
            cout<<ancestor[Find(Que[k][i].first)]<<endl; 
            return; 
        } 
    } 
    
}
int main() {
     int T; 
     cin>>T; 
     while(T--) { 
        Init(); 
        for(int i=1;i<=n;i++) 
            if(!indegree[i]){ 
                LCA(i); 
                break; 
            } 
    } 
    return 0; 
}