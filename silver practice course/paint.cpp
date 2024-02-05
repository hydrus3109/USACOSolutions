#include <iostream>
using namespace std;
 
#define MAX_N 100000
int N, Q, min_since_last[26], prefix[MAX_N+1], suffix[MAX_N+2];
 
int main(void)
{
  string s;
  cin >> N >> Q >> s;
 
  // Build prefix counts of # of strokes needed
  for (int c=0; c<26; c++) min_since_last[c] = -1;
  for (int i=1; i<=N; i++) {
    int curchar = s[i-1] - 'A'; 
    for (int c=0; c<26; c++) min_since_last[c] = min(curchar, min_since_last[c]);
    prefix[i] = prefix[i-1];
    if (min_since_last[curchar] < curchar) prefix[i]++;
    min_since_last[curchar] = curchar;
  }
 
  // Build suffix counts of # of strokes needed
  for (int c=0; c<26; c++) min_since_last[c] = -1;
  for (int i=N; i>=1; i--) {
    int curchar = s[i-1] - 'A'; 
    for (int c=0; c<26; c++) min_since_last[c] = min(curchar, min_since_last[c]);
    suffix[i] = suffix[i+1];
    if (min_since_last[curchar] < curchar) suffix[i]++;
    min_since_last[curchar] = curchar;
  }
 
  for (int i=0; i<Q; i++) {
    int x, y;
    cin >> x >> y;
    cout << prefix[x-1] + suffix[y+1] << "\n";
  }
}