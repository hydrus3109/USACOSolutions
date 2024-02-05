#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, M;
vector<string> A;

int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

char get(int r, int c) {
  if (r < 0 || N <= r || c < 0 || M <= c) {
    // we are outside the grid, return a non-letter
    return '_';
  }
  
  return A[r][c];
}

int main() {
  freopen("moocrypt.in", "r", stdin);
  freopen("moocrypt.out", "w", stdout);

  cin >> N >> M;
  A.resize(N);
  for (int i = 0; i < M; i++) {
    cin >> A[i];
  }

  int best = 0;
  for (char mch = 'A'; mch <= 'Z'; mch++) {
    // pick a character that will be set to M
    if (mch == 'M') {
      continue;
    }
    for (char och = 'A'; och <= 'Z'; och++) {
      // pick a character that will be set to O
      if (och == 'O' || mch == och) {
        continue;
      }
      int result = 0;
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          // check the first character would be M
          if (get(i, j) != mch) {
            continue;
          }
          // try all possible words starting at square (i,j)
          for (int k = 0; k < 8; k++) {
            // check the next two characters would be O
            if (get(i + 1 * dr[k], j + 1 * dc[k]) == och &&
                get(i + 2 * dr[k], j + 2 * dc[k]) == och) {
              result++;
            }
          }
        }
      }
      best = max(best, result);
    }
  }
  cout << best << endl;

  return 0;
}