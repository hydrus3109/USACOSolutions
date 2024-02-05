#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
vector<ll> arr;
ll n;

bool check(ll index) {
    ll count = 0;
    ll tally = 1;
    
    while (index != 0) {
        count += index--;
        for (; tally <= n; ++tally) {
            if (arr.at(tally) >= count) {
                ++tally;
                break;
            }
        }
    }
    
    return tally > n;
}

int main() {
    ll testCases;
    cin >> testCases;
    for(int i = 0; i < testCases; i++) {
        cin >> n;
        arr.resize(n + 1); 
        for (ll j = 1; j <= n; ++j) {
            cin >> arr.at(j);
        }
        sort(arr.begin() + 1, arr.end());

        ll low = 1, high = n;
        ll ans = arr.at(n);
        while (low < high) {
            ll mid = low + (high - low) / 2;
            if (check(mid)) high = mid;
            else low = mid + 1;
        }
        if (check(low)) ans = min(ans, low * (low + 1) / 2);
        cout << ans << endl;
    }
    return 0;
}
