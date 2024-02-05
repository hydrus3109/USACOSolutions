#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
#define MAXN 1000005
int T[MAXN+1];
int A[MAXN];
long long int inv[10000];
int num;
int getSum(int i)
{
	int c=0;
	for(++i; i > 0 ; i -= (i & -i))
		c += T[i];
	return c;
}
void set(int i,int dif)
{
	for(++i; i < MAXN ; i += (i & -i))
		T[i] += dif;
}

int main(){
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> A[i];
        inv[A[i]] +=  i - getSum(A[i]);
        set(A[i],1);
    }
    long long int ans;
    for(int i = 0; i < num; i++){
        cout << ans << endl;
        ans += inv[i];
    }
    
    return 0;
}