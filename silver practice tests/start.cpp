#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int main(){
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    int x,y,k,n;
    fin >> x >> y >> k >> n;
    vector<vector<bool>> start;
    start.resize(x+1, vector<bool>(y+1));
    start[0][0] = true;
    for(int i =0; i < k; i++){
        vector<vector<bool>> next;
        next.resize(x+1, vector<bool>(y+1));
        for(int j = 0; j <= x; j++){
            for(int z = 0; z <= y; z++){
                if(start[j][z] == false) continue;
                next[j][z] = true;
                next[x][z] = true;
                next[0][z] = true;
                next[j][y] = true;
                next[j][0] = true;
                int moveRight = min(j, y - z);
				next[j-moveRight][z+moveRight] = true;
				// pour from size Y bucket to size X bucket
				int moveLeft = min(x - j, z);
				next[j+moveLeft][z-moveLeft] = true;
            }
            
        }
        start = next;
    }
    int closest = -1;                                           
    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++){
            if(start[i][j] == false) continue;
            if(closest == -1) closest = abs(n-i-j);
            closest = min(closest, abs(n-i-j));
        }

    }
    fout << closest << endl;                                