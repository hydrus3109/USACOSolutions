#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
const int maxn=1000;
struct{
    int l,r;
    int cnt;
}tree[maxn*4];
int N,M,P;
int ans=0;
void build(int k,int l,int r){
    tree[k].l=l;  tree[k].r=r;
    if (l==r) return;
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
}
void insert(int k,int l,int r, int sign){
    if (r<tree[k].l || tree[k].r<l) return;
    if (l<=tree[k].l && tree[k].r<=r){      
        tree[k].cnt = ;
        return;
    }
    insert(k*2,l,r);
    insert(k*2+1,l,r);
}
void setzero(int k,int l,int r){
    if (l==r) return;
    if (l<=tree[k].l && tree[k].r<=r){      
        tree[k].cnt=0;
    }
    insert(k*2,l,r);
    insert(k*2+1,l,r);
}
void find(int k,int l,int r){
    if (r<tree[k].l || tree[k].r<l) return;
    ans+=tree[k].cnt;
    find(k*2,l,r);
    find(k*2+1,l,r);
}
int main(){
    build(1,0,1000);
    cin >> N >> M;
    int L,R,C;
    for (int i=1;i<=M;i++){
        int a; cin >> a;
        if(a == 0){
            scanf("%d%d%d",&L,&R,&C);
            insert(1,L,R-1);
        }
        else{
            scanf("%d",&P);
            find(1,P,P);
            printf("%d\n",ans);
        }

    }
    return 0;
}
