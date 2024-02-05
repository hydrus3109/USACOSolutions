#include <cstdio>
#include <algorithm>
#include <fstream>
using namespace std;

struct Entry {
  int index;
  int value;
};

Entry entries[100000];

int main() {
	ifstream fin ("sort.in");
	ofstream fout ("sort.out");
  int n;
  fin >> n;

  for (int i = 0; i < n; i++) {
    entries[i].index = i;
    fin >> entries[i].value;
  }

  sort(entries, entries + n, [](Entry a, Entry b) {
    // Break ties by making the smaller element be whichever
    // element was first in the array originally.
    return a.value < b.value || (a.value == b.value && a.index < b.index);
  });

  int answer = 0;
  for (int j = 0; j < n; j++) {
    // In terms of the notation from the above analysis, we have,
    // entries[j].index = i
    // j = a_i
    answer = max(answer, entries[j].index - j);
  }

  fout << answer + 1;
}