#include <iostream>
using namespace std;
int n, a1[100010], tot, now, d = 1;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a1[i];
        tot += a1[i];
    }
    while (tot) {
        if (a1[now] >= 2) {
            while (a1[now] >= 2) {
                a1[now]--;
                cout << (d == 1 ? "R" : "L");
                now += d;
                tot--;
            }
            now -= d;
            d = -d;
        } else {
            cout << (d == 1 ? "R" : "L");
            a1[now]--;
            tot--;
            now += d;
        }
    }
    cout << endl;
    return 0;
}