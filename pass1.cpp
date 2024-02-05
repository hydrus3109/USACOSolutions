#include <bits/stdc++.h>
using namespace std;

vector<int> X, Y, Xp, Yp;
map<int, int> Mx, My;
int x, y, z, tt;
int x3, y3;
int px, py;

bool check(int xx) {
    int kx = xx / 2, ky = xx / 2, tt2 = tt ^ (xx % 2);
    if (xx % 2 == 1) tt == 1 ? kx++ : ky++;
    if (xx == 0) {
        x3 = tt == 1 ? x + z : x;
        y3 = tt == 1 ? y : y + z;
    }
    if (px + kx >= Xp.size() || py + ky >= Yp.size()) return false;

    int nx = max(x, px + kx >= 0 ? Xp[px + kx] : x);
    int ny = max(y, py + ky >= 0 ? Yp[py + ky] : y);
    x3 = tt2 == 1 ? z - (nx - x + ny - y) + nx : nx;
    y3 = tt2 == 1 ? ny : z - (nx - x + ny - y) + ny;

    return (nx - x + ny - y) <= z;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        char dir;
        int coord;
        cin >> dir >> coord;
        (dir == 'V' ? X : Y).push_back(coord);
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    for (int i = 1; i < X.size(); i++) if ((X[i] - X[i - 1]) % 2 == 1) Xp.push_back(X[i]);
    for (int i = 1; i < Y.size(); i++) if ((Y[i] - Y[i - 1]) % 2 == 1) Yp.push_back(Y[i]);
    for (int i = 0; i < X.size(); i++) Mx[X[i]] = i;
    for (int i = 0; i < Y.size(); i++) My[Y[i]] = i;

    while (m--) {
        cin >> x >> y >> z;
        tt = 1;
        vector<int>& relevant = Mx.count(x) ? Y : X;
        auto it = lower_bound(relevant.begin(), relevant.end(), Mx.count(x) ? y : x);
        if (it == relevant.end() || *it - (Mx.count(x) ? y : x) >= z) {
            cout << x + (!Mx.count(x) ? z : 0) << " " << y + (Mx.count(x) ? z : 0) << endl;
            continue;
        }

        tt = ((*it) - (Mx.count(x) ? y : x)) % 2 == 0 ? 0 : 1;
        z -= *it - (Mx.count(x) ? y : x);
        Mx.count(x) ? y = *it : x = *it;

        px = upper_bound(Xp.begin(), Xp.end(), x) - Xp.begin() - 1;
        py = upper_bound(Yp.begin(), Yp.end(), y) - Yp.begin() - 1;
        int h = 0, t = n;
        check(2);
        while (h < t) {
            int mid = (h + t + 1) / 2;
            check(mid) ? h = mid : t = mid - 1;
        }

        check(h);
        cout << x3 << " " << y3 << endl;
    }
    return 0;
}
