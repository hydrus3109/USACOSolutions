#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include<cstring>
#include<queue>
using namespace std;
class Solution {
    
public:
    int conveyorBelt(vector<string>& matrix, vector<int>& start, vector<int>& end) {
        vector<pair<int,int>> adj[100];
        int numbers[100][100];
        int dist[100001] = {INT_MAX};
        int start1 = 0;
        int startnum;
        int endnum;
        for(int i = 0; i < matrix.size(); i++){
            for(int j=0; j < matrix[i].length(); j++ ){
                numbers[i][j] = start1;
                if(i == start[0] and j == start[1]) startnum=start1;
                if(i == end[0] and j == end[1]) endnum=start1;
                start1++;
            }
        }
        for(int i = 0; i < matrix.size(); i++) {
            for(int j=0; j < matrix[i].length(); j++ ){
                char check = matrix[i][j];
                int num = numbers[i][j];
                if(check == '<' and j > 0) {
                    adj[num].push_back({numbers[i][j-1], 0});
                    if(j < matrix[0].length()-1) adj[num].push_back({numbers[i][j+1], 1});
                    if(i > 0) adj[num].push_back({numbers[i-1][j], 1});
                    if(i < matrix.size()-1) adj[num].push_back({numbers[i+1][j], 1});
                }
                if(check == '>' and j < matrix[0].length()-1){
                    adj[num].push_back({numbers[i][j+1], 0});
                    if( j > 0) adj[num].push_back({numbers[i][j-1], 1});
                    if(i > 0) adj[num].push_back({numbers[i-1][j], 1});
                    if(i < matrix.size()-1) adj[num].push_back({numbers[i+1][j], 1});
                }
                if(check == '^' and i > 0){
                    adj[num].push_back({numbers[i-1][j], 0});
                    if(i < matrix.size()-1) adj[num].push_back({numbers[i+1][j], 1});
                    if( j > 0) adj[num].push_back({numbers[i][j-1], 1});
                    if(j < matrix[0].length()-1) adj[num].push_back({numbers[i][j+1], 1});
                }
                if(check == 'v' and i < matrix.size()-1){
                    adj[num].push_back({numbers[i+1][j], 0});
                    if( j > 0) adj[num].push_back({numbers[i][j-1], 1});
                    if(i > 0) adj[num].push_back({numbers[i-1][j], 1});
                    if(j < matrix[0].length()-1) adj[num].push_back({numbers[i][j+1], 1});
                }
                
            }
        }
        queue<pair<int,int>> que; 
        que.push({startnum,0});
        dist[startnum]=0;
        int max = -1;
        while(que.empty()!=false){
            pair<int,int> front = que.front();
            if(front.first== endnum)
                if(front.second < dist[endnum]) dist[endnum] = front.second;
            que.pop();
            for(int i = 0; i < adj[front.first].size(); i++){
                pair<int,int> go = adj[front.first][i];
                int newmax = go.second + front.second;
                if (newmax < dist[go.first]){
                    que.push({go.first,newmax});
                    dist[go.first] = newmax;
                }

            }


        }
        return dist[endnum];

    }
}; 

int main(){
    Solution
}