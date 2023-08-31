#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define LL long long
#define MAXN 2005
#define INF 0x3f3f3f3f

using namespace std;

struct Node{
    int u,v,w;
    Node(){}
    Node(int _u,int _v,int _w){
        u=_u;
        v=_v;
        w=_w;
    }
    bool operator < (const Node &other) const{
        return w<other.w;
    }
};
int n,m;
int u,v,w;
int res;
vector<Node>edge;
int bin[MAXN];

int findx(int x){
    int cur=x;
    while(x!=bin[x]) x=bin[x];
    bin[cur]=x;
    return x;
}
void init(){
    edge.clear();
    res=-1;    
    for(int i=0;i<=n;i++) bin[i]=i;
}

int main(){ 
    while(scanf("%d%d",&n,&m)!=EOF){
        init();
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            edge.push_back(Node(u,v,w));
            edge.push_back(Node(v,u,w));
        }
        sort(edge.begin(), edge.end());
        for(int i=0;i<edge.size();i++){
            int fx=findx(edge[i].u);
            int fy=findx(edge[i].v);
            if(fx!=fy){
                bin[fx]=fy;
                res=max(res,edge[i].w);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
