#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
int n,k,a[100001][2],f[101][100001];
void kp1(int l,int r){
    int x=l,y=r,mai=a[(l+r)/2][1];
    while(x<y){
        while(a[x][1]<mai)x++;
        while(a[y][1]>mai)y--;
        if(x<=y){
            swap(a[x][0],a[y][0]);
            swap(a[x][1],a[y][1]);
            x++;y--;
        }
    }if(x<r)kp1(x,r);if(l<y)kp1(l,y);
}
int main(){
	ifstream fin ("lifeguards.in");
	ofstream fout ("lifeguards.out");
	k = 1;
    fin >> n;
    for(int i=1;i<=n;i++) fin >> a[i][0] >> a[i][1];
    kp1(1,n);
    for(int i=1;i<=n;i++)f[0][i]=f[0][i-1]+a[i][1]-max(a[i-1][1],a[i][0]);
    for(int i=1;i<=k;i++){
        for(int j=i+1;j<=n;j++){
            for(int k1=0;k1<=i;k1++){
                f[i][j]=max(f[i][j],f[i-k1][j-k1-1]+a[j][1]-max(a[j-k1-1][1],a[j][0]));
            }
        }
    }
    int ans=f[k][n];
    for(int i=1;i<=k;i++)ans=max(ans,f[k-i][n-i]);
	fout << ans << endl;
    return 0;
}