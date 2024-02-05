#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long

using namespace std;

const int p=1e9+7;
const int N=755;
int a[N][N],r,c,K,root[N*N],sz=0;
int f[N][N],sum[N][N],sum_line[N];
struct node{
    int sum;
    int l,r;
};
node t[6001000];

void change(int &rt,int l,int r,int w,int z) {
    if (!rt) rt=++sz;
    if (l==r) {
        t[rt].sum+=z; t[rt].sum%=p;
        return;
    }
    int mid=(l+r)>>1;
    if (w<=mid) change(t[rt].l,l,mid,w,z);
    else change(t[rt].r,mid+1,r,w,z);
    t[rt].sum=(t[t[rt].l].sum%p+t[t[rt].r].sum%p)%p;
} 

int ask(int bh,int l,int r,int L,int R) {
    if (!bh) return 0;
    if (l>=L&&r<=R) return t[bh].sum%p;
    int mid=(l+r)>>1;
    int ans=0;
    if (L<=mid) ans=(ans+ask(t[bh].l,l,mid,L,R)%p)%p;
    if (R>mid) ans=(ans+ask(t[bh].r,mid+1,r,L,R)%p)%p;
    return ans%p;
}

int main() 
{
    scanf("%d%d%d",&r,&c,&K);
    for (int i=1;i<=r;i++)
        for (int j=1;j<=c;j++)
            scanf("%d",&a[i][j]);

    for (int i=1;i<=c;i++) sum[1][i]=1;
    for (int i=1;i<=r;i++) sum[i][1]=1;
    f[1][1]=1;
    change(root[a[1][1]],1,c,1,1);

    for (int i=2;i<=r;i++) {
        for (int j=c;j>=1;j--) {
            f[i][j]=((sum[i-1][j-1]%p-ask(root[a[i][j]],1,c,1,j-1)%p)%p+p)%p;
            change(root[a[i][j]],1,c,j,f[i][j]);
        }
        for (int j=1;j<=c;j++) 
            sum[i][j]=(((f[i][j]+sum[i-1][j])%p+sum[i][j-1])%p-sum[i-1][j-1]+p)%p;
    }

    printf("%d\n",f[r][c]);
    return 0;
}