
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int N=1005;
const int INF=0x3fffffff ;
int m,n;
int a[N];
int dp[N][N][2];
 
int min(int x,int y)
{
    return x>y?y:x;
}
 
int main()
{
    int k;
    while(~scanf("%d %d",&m,&n))
    {
        for(int i=1;i<=m;i++)
            scanf("%d",&a[i]);
        a[++m]=n;
        sort(a+1,a+m+1);
        n=lower_bound(a+1,a+m+1,n)-a;
 
        for(int i=0;i<=m;i++)
            for(int j=0;j<=m;j++)
               dp[i][j][0]=dp[i][j][1]=INF;
        dp[n][n][0]=dp[n][n][1]=0;
 
        for(int i=n;i>=1;--i)
        {
            for(int j=n;j<=m;j++)
            {
                if(i==j) continue;//
                k=m-(j-i);
                dp[i][j][0]=min(dp[i+1][j][0]+(a[i+1]-a[i])*k,dp[i+1][j][1]+(a[j]-a[i])*k);
                dp[i][j][1]=min(dp[i][j-1][0]+(a[j]-a[i])*k,dp[i][j-1][1]+(a[j]-a[j-1])*k);
            }
        }
        printf("%d\n",min(dp[1][m][0],dp[1][m][1]));
    }
    return 0;
}