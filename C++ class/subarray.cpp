
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // For each element, find the minimum change to create two equal subarray sums
    for (int i = 0; i < N; ++i) {
        ll min_change = numeric_limits<ll>::max();

        // Calculate prefix sums and store them with their frequency
        unordered_map<ll, int> prefix_sums;
        ll sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += a[j];
            prefix_sums[sum]++;
        }

        // Find the minimum change for each element
        ll current_sum = 0;
        for (int j = 0; j < N; ++j) {
            if (j != i) current_sum += a[j];

            // Check if changing the current element can make two subarray sums equal
            for (const auto& p : prefix_sums) {
                ll needed_change = p.first - current_sum - a[i];
                if (abs(needed_change) < min_change && prefix_sums[current_sum + a[i] + needed_change] > 0) {
                    min_change = abs(needed_change);
                }
            }
        }

        // Output the minimum change
        if (min_change == numeric_limits<ll>::max()) {
            cout << "No possible change" << endl;
        } else {
            cout << min_change << endl;
        }
    }

    return 0;
}