#include<cstdio>
#include<algorithm>
#define ll long long
#define N 110000
using namespace std;
inline char gc(){
    static char now[1<<16],*S,*T;
    if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}
    return *S++;
}
inline int read(){
    int x=0,f=1;char ch=gc();
    while(ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=gc();}
    while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=gc();
    return x*f;
}
struct node{
    int nd,pri;
}s[N];
int n,m,r,milk[N],price[N];ll sum[N],sum1[N];
inline bool cmp1(const int &a,const int &b){return a>b;}
inline bool cmp(const node &a,const node &b){return a.pri>b.pri;}
int main(){
    freopen("rental.in","r",stdin);
    freopen("rental.out","w",stdout);
    n=read();m=read();r=read();
    for (int i=1;i<=n;++i) milk[i]=read();sort(milk+1,milk+n+1,cmp1);
    for (int i=1;i<=m;++i) s[i].nd=read(),s[i].pri=read();
    sort(s+1,s+m+1,cmp);int now=1,now1=1;
    for (int i=1;i<=r;++i) price[i]=read();sort(price+1,price+r+1,cmp1);ll ans=0;
    for (int i=1;i<=r;++i) sum[i]=sum[i-1]+price[i];
    for (int i=1;i<=n;++i){
        ll tmp1=0;int c=milk[i],pre=now;node e=s[now];
        while(c>=s[now].nd&&now<=m){
            tmp1+=(ll)s[now].nd*s[now].pri;
            c-=s[now].nd;++now;e=s[now];
        }tmp1+=(ll)c*s[now].pri;e.nd-=c;
        sum1[i]=sum1[i-1]+tmp1;s[now]=e;
    }
    for (int i=1;i<=n;++i) ans=max(ans,sum1[i]+sum[n-i]);
    printf("%lld\n",ans);
    return 0;
}