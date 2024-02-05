#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#define maxn 200010
#define INF 0x7fffffff
#define inf 10000000
#define ull unsigned long long
#define ll long long
using namespace std;
 
int a[maxn], arr[maxn];
 
int lowbit(int x)
{
    return x&(-x);
}
 
int sum(int x)
{
    int ret = 0;
    while(x > 0)
        ret += a[x], x -= lowbit(x);
    return ret;
}
 
void add(int x, int d)
{
    while(x < maxn)
        a[x] += d, x += lowbit(x);
}
 
void init()
{
    memset(arr, 0, sizeof(arr));
    memset(a, 0, sizeof(a));
}
int main()
{
    int num; cin >> num;
    for(int i =0; i < num;i++) {cin >> arr[i]; add(i,arr[i]);}
    int quer;
    cin >> quer;
    for(int i = 0; i < quer; i++){
        char a; int b,c;
        cin >> a >> b >> c;
        if(a == 'q')  cout << sum(c) - sum(b) << endl;
        else add(b,c);
    }
    do{
        int a = INT_MAX; 
        while(a > 0){
            if(a)
        }
    }
    return 0;
}