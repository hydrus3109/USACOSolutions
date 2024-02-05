#include <iostream>
#include <vector>

using namespace std;

int main() {
  freopen("cow.in", "r", stdin);
  freopen("cow.out", "w", stdout);

  int N;
  string S;
  cin >> N >> S;

  long long NC = 0;
  long long NO = 0;
  long long NW = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'C') {
      NC++;
    } else if (S[i] == 'O') {
      NO += NC;
    } else if (S[i] == 'W') {
      NW += NO;
    }
  }

  cout << NW << endl;
  return 0;
}