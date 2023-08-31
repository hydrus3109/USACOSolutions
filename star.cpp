#include <cstdio>
#include <cstring> 
#include <iostream>
#define ll long long
using namespace std;

const ll N = 2e4 + 5;
const ll M = 4e4 + 5;

ll n, c[M], level[N];

ll lowbit(ll x) {
    return x & (-x);
}

void update(ll x) {
    while (x < M) {
        c[x]++;
        x += lowbit(x);
    }
}

ll getsum(ll x) {
    ll sum = 0;
    while (x) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}

int main() {
    cin >> n;
    memset(c,0, sizeof(c));
    memset(level, 0 , sizeof(level));
    for (ll i = 1; i <= n; i++) {
        int x,y; 
        cin >> x>> y;
        x++;
        level[getsum(x)]++;
        update(x);
    }
    for (ll i = 0; i < n; i++) {
        printf("%lld\n", level[i]);
    }
    return 0;
}