#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> flightRoutes(N, vector<int>(N, 0));
    int numDirectFlights = 0;

    // Reading parity information
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            cin >> flightRoutes[i][i + j + 1];
        }
    }

    // Iterating over each pair of cities
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (flightRoutes[i][j] == 1) { // If parity is odd, there is a direct flight
                numDirectFlights++;
                for (int k = j + 1; k < N; ++k) {
                    // Update parity for other routes affected by this direct flight
                    if (flightRoutes[i][k] != -1) { 
                        flightRoutes[i][k] = 1 - flightRoutes[i][k];
                    }
                    if (flightRoutes[j][k] != -1) {
                        flightRoutes[j][k] = 1 - flightRoutes[j][k];
                    }
                }
            }
        }
    }

    cout << numDirectFlights << endl;
    return 0;
}
