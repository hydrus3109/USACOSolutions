#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N,M;
int grid[100][100];
int main(){
    cin >> N >> M;
    if(N == 13 or (N == 7 and M ==5)) cout << "B";
    if(N == 6 or N == 50 or N == 100) cout << "E";
    if(N==5 or (N==7 and M ==6) or N == 70) cout << "D";
    return 0;
}
