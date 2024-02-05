#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  // Read in the size of the array and initialize the array
  int n;
  cin >> n;
  vector<int> a(n);

  // Read in the range of each subarray
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // Initialize the minimum and maximum values of the array
  int min_val = -109;
  int max_val = 109;

  // Set the first element of the array to the minimum value
  a[0] = min_val;

  // Set the rest of the elements of the array using the given ranges
  for (int i = 1; i < n; i++) {
    // Set the current element to the maximum of the previous element and the minimum value
    a[i] = max(a[i - 1], min_val);

    // Update the minimum and maximum values
    min_val = a[i] - a[i - 1];
    max_val = a[i] + a[i - 1];
  }

  // Print the array
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}
