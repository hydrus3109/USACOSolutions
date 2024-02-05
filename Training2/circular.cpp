#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int T, N;
int a[MAXN];

// Check if a number is prime
bool isPrime(int x) {
  if (x < 2) return false;
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];

    // We will simulate the game and keep track of the number of cows in
    // each room as we go along
    int cur = 1, fj_cows = 0, nhoj_cows = 0;
    bool fj_turn = true; // Farmer John goes first
    while (true) {
      // The current player takes a turn
      if (fj_turn) {
        fj_cows += a[cur];
        // Find the largest prime number that is at most the number of cows
        // in the current room
        int p = 0;
        for (int i = a[cur]; i >= 1; i--) {
          if (isPrime(i)) {
            p = i;
            break;
          }
        }
        // Remove p cows from the current room
        a[cur] -= p;
      } else {
        nhoj_cows += a[cur];
        // Find the largest prime number that is at most the number of cows
        // in the current room
        int p = 0;
        for (int i = a[cur]; i >= 1; i--) {
          if (isPrime(i)) {
            p = i;
            break;
          }
        }
        // Remove p cows from the current room
        a[cur] -= p;
      }
      fj_turn = !fj_turn; // Switch turn

      // Check if the game is over
      if (a[cur] == 0) {
        // If it's Farmer John's turn, Farmer Nhoj wins, otherwise Farmer John wins
        if (fj_turn) {
          cout << "Farmer Nhoj" << endl;
        } else {
          cout << "Farmer John" << endl;
        }
        break;
      }

      // Move to the next room
      cur++;
      if (cur > N) cur = 1;
    }
  }
  return 0;
}
