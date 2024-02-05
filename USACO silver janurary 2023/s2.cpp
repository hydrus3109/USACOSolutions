#include <cstdio>

using namespace std;

const int N = 1505;

int sz2[N][N], ed[N][N];
char s1[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s%d", s1[i] + 1, &ed[i][n + 1]);
  for (int i = 1; i <= n; i++) scanf("%d", &ed[n + 1][i]);

  
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      sz2[i][j]++;
      if (s1[i][j] == 'D')
        sz2[i + 1][j] += sz2[i][j];
      else
        sz2[i][j + 1] += sz2[i][j];
    }
  int ans = 0;
  for (int i = n; i >= 1; i--)
    for (int j = n; j >= 1; j--) {
      if (s1[i][j] == 'D')
        ed[i][j] = ed[i + 1][j];
      else
        ed[i][j] = ed[i][j + 1];
      ans += ed[i][j];
    }
  printf("%d\n", ans);
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, y, c = 0;
    scanf("%d%d", &x, &y);
    for (int i = x, j = y; i <= n && j <= n;) {
      if (s1[i][j] == 'D')
        i++;
      else
        j++;
      c = ed[i][j];
    }
    ans -= sz2[x][y] * c;
    if (s1[x][y] == 'R') {
      for (int i = x, j = y + 1; i <= n && j <= n;) {
        sz2[i][j] -= sz2[x][y];
        if (s1[i][j] == 'R')
          j++;
        else
          i++;
      }
      for (int i = x + 1, j = y; i <= n && j <= n;) {
        sz2[i][j] += sz2[x][y];
        if (s1[i][j] == 'R')
          j++;
        else
          i++;
      }
      s1[x][y] = 'D';
    } else {
      for (int i = x, j = y + 1; i <= n && j <= n;) {
        sz2[i][j] += sz2[x][y];
        if (s1[i][j] == 'R')
          j++;
        else
          i++;
      }
      for (int i = x + 1, j = y; i <= n && j <= n;) {
        sz2[i][j] -= sz2[x][y];
        if (s1[i][j] == 'R')
          j++;
        else
          i++;
      }
      s1[x][y] = 'R';
    }
    for (int i = x, j = y; i <= n && j <= n;) {
      if (s1[i][j] == 'D')
        i++;
      else
        j++;
      c = ed[i][j];
    }
    ans += sz2[x][y] * c;
    printf("%d\n", ans);
  }
  return 0;
}