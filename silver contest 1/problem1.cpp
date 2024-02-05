#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool sortbysecdesc(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return a.second>b.second;
}
int main(){
    ifstream fin("infile.txt");
    int k,m,n;
    vector<pair<int,int>> locations;
    cin >> k >> m >> n;
    for(int i = 0; i < k; i++){
        int a,b; cin >> a >> b;
        locations.push_back({a,b});
    }

    vector<bool> stopped;
    stopped.resize(k-1);
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        for(int j = 0; j < k-1; j++){
            if(stopped[j] == true) continue;
            if(locations[j].first < a and a < locations[j+1].first){ stopped[j] = true; break;}
        }
    }
    for(int j = 0; j < k-2; j++){
       if(j !=0){ if(stopped[j-1] == true and stopped[j+1] == true) stopped[j] = true;}
   }
    vector<bool> visited;
    visited.resize(k-1);
    vector<int> answer;
    answer.resize(k-1);
    for(int i = 0; i < k-1; i++){
        if(stopped[i] == true) {answer[i] = locations[i].second; continue;}
        if(visited[i] == true) {answer[i] = 0; continue;}
        answer[i] += locations[i].second;
        answer[i] += locations[i+1].second;
        bool found = false;
        int current = i+1;
        while(found == false){
            if(current < k-1){
                if(stopped[current] != true){
                    current++;
                    answer[i] += locations[current+1].second;
                    visited[current] == true;
                }
                else{
                    found = true;
                }
            }
            else{
                found = true;
            }
            
        }
    }
    sort(answer.begin(), answer.end(), greater<int>());
    int final = 0;
    if(answer[0] == 0){
        sort(locations.begin(),locations.end(),sortbysecdesc);
        for(int i =0; i < n;i++){
            final+= locations[i].second;
        }
    }
    else{
        for(int i =0; i < n;i++){
            final+= answer[i];
        }
    }
    cout << final;
    return 0;
}
