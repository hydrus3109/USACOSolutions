#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXX = 1e6;
int N, Q;
long long x[MAXN], prefixSum[MAXN];

// Function to compute the waste for a given y
long long computeWaste(long long y, int a, int b) {
    int idx = lower_bound(x, x + N, y) - x;
    long long leftSum = y * idx - prefixSum[idx];
    long long rightSum = (prefixSum[N] - prefixSum[idx]) - y * (N - idx);
    return a * leftSum + b * rightSum;
}

// Ternary search to find the minimum waste
long long ternarySearch(int a, int b) {
    long long l = 0, r = MAXX;
    while (r - l > 3) {
        long long m1 = l + (r - l) / 3;
        long long m2 = r - (r - l) / 3;
        long long f1 = computeWaste(m1, a, b);
        long long f2 = computeWaste(m2, a, b);
        if (f1 < f2) r = m2;
        else l = m1;
    }

    long long minWaste = computeWaste(l, a, b);
    for (long long i = l + 1; i <= r; ++i) {
        minWaste = min(minWaste, computeWaste(i, a, b));
    }
    return minWaste;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }
    sort(x, x + N);

    // Compute prefix sums
    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + x[i];
    }

    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << ternarySearch(a, b) << "\n";
    }
    return 0;
}
