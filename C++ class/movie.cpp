#include <iostream>
#include <vector>
#include <math.h>
#include<queue>
using namespace std;
typedef pair<int,int> ipair;
vector<ipair> coords;
deque<int> movies;
int positions[100000];
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int n,m;
        for(int i =1;i <= n;i++){
            movies.push_back(i);
            positions[i] = i-1;
        }
        for (int i = 0; i < m; i++)
        {
            int req; cin >> req;
            for(int i = 0; i < positions[req]; i++){
                positions[movies[i]]++;
            }
            movies.erase(movies.begin()+positions[req]);
            movies.push_front(req);
            cout << positions[req] << " ";
            positions[req] = 0;
        }
        cout << endl;
        
    }
	return 0;
}
