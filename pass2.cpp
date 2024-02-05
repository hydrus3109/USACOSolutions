#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
using ll = long long;
constexpr int N = 1e6 + 100, mod = 1e9 + 7;

ll n, Q_book[10005][2], dp[1000][10005], sum[1000][10005];
int Q, C, type[1000], b_mn[1000];
set<ll> point_book;
map<ll, int> point_rank;
map<int, ll> point_val;

void start() {
    int tim = 0;
    point_val[0] = 0;
    for(auto x: point_book) {
        point_rank[x] = ++tim;
        point_val[tim] = x;
    }
}

void real_set(int idx, int set_type) {
    if (type[idx] == -1 || type[idx] == 1) {
        type[idx] = set_type;
    } else if ((type[idx] == 2 && set_type == 3) || (type[idx] == 3 && set_type == 2)) {
        cout << 0 << endl;
        exit(0);
    }
}

void set_type() {
    memset(type, -1, sizeof(type));
    memset(b_mn, 0x3f, sizeof(b_mn));
    for (int i = 0; i < Q; ++i) {
        ll a = Q_book[i][0], b = Q_book[i][1] - 1, c = Q_book[i][1];
        int a_idx = point_rank[a], b_idx = point_rank[b], c_idx = point_rank[c];
        real_set(a_idx, 1);
        real_set(c_idx, 3);
        if (b != a) {
            real_set(b_idx, 2);
            b_mn[b_idx] = min(b_mn[b_idx], a_idx);
        }
    }
}

ll quick_pow(ll x, ll n) {
    ll ret = 1;
    for (; n; n >>= 1, x = x * x % mod) {
        if (n & 1) ret = ret * x % mod;
    }
    return ret;
}

int main() {
    cin >> n >> Q >> C;
    for (int i = 0; i < Q; ++i) {
        cin >> Q_book[i][0] >> Q_book[i][1];
        point_book.insert(begin(Q_book[i]), end(Q_book[i]));
        point_book.insert(Q_book[i][1] - 1);
    }
    start();
    set_type();
    int m = point_book.size();
    dp[0][0] = sum[0][0] = 1;
    for (int j = 1; j <= C; ++j) sum[0][j] = sum[0][j - 1] + dp[0][j];
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (type[i] == 1) {
                ll seg_len = point_val[i] - point_val[i - 1];
                ll o1 = (quick_pow(j, seg_len) - quick_pow(j - 1, seg_len) + mod) % mod * sum[i - 1][j - 1] % mod;
                ll o2 = dp[i - 1][j] * quick_pow(j, seg_len) % mod;
                dp[i][j] = (o1 + o2) % mod;
            } else if (type[i] == 2) {
                dp[i][j] = dp[b_mn[i]][j] * quick_pow(j, point_val[i] - point_val[b_mn[i]]) % mod;
            } else if (type[i] == 3) {
                dp[i][j] = sum[i - 1][j - 1];
            }
            sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
        }
    }
    cout << sum[m][C] * quick_pow(C, n - point_val[m]) % mod << endl;
    return 0;
}
