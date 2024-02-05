//#include<bits/stdc++.h>
#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
//#define UP(i,x,y) for(int i=x;i<=y;i++)
//#define DOWN(i,x,y) for(int i=x;i>=y;i--)
#define sddd(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define sdd(x,y) scanf("%d%d", &x, &y)
#define sd(x) scanf("%d", &x)
//#define mp make_pair
#define pb push_back
#define ms(x, y) memset(x, y, sizeof x)
using namespace std;
typedef long long ll;
#define MOD 1000000007
const int maxn = 510;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
int n, w, h, s, t;
int bit[maxn][maxn];
 
int lowbit(int x)
{
    return x&(-x);
}
void add(int x, int y, int v)
{
    for(int i = x; i <= h; i+=lowbit(i))
    {
        for(int j = y; j <= w; j+=lowbit(j))
        {
            bit[i][j] += v;
        }
    }
}
int query(int x, int y)
{
    int res = 0;
    for(int i = x; i; i-=lowbit(i))
    {
        for(int j = y; j; j-=lowbit(j))
        {
            res+=bit[i][j];
        }
    }
    return res;
}
int main()
{
	//freopen("out.txt", "w", stdout);
	while(~sd(n)&&n)
    {
        sdd(w, h);
        ms(bit, 0);
        int ta, tb;
        for(int i = 0; i < n; i++)
        {
            sdd(ta, tb);
            add(tb, ta, 1);
        }
        sdd(s, t);
        int ans = -1, fs, ft;
        for(int i = t; i <= h; i++)
        {
            for(int j = s; j <= w; j++)
            {
                int temp = query(i, j) - query(i-t, j) - query(i, j-s) + query(i-t,j-s);
                if(temp > ans)
                {
                    ans = temp;
                    ft = i;
                    fs = j;
                }
            }
        }
        printf("%d\n", ans);
    }
	return 0;
}