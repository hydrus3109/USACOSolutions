#include <cstdio>
#include <cstring> 
#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#define ll long long
using namespace std;

const ll N = 2e4 + 5;
const ll M = 4e4 + 5;

ll n, c[M], level[N];
struct edge{
    int start;
    int end;
    int weight;
};

int father[100001];
int weight[100001];
int length[109];
bool operator<(edge s1, edge s2){
    return s1.weight< s2.weight;
}

int find(int a){
    int temp = a;
    while(father[temp] != temp){
        temp = father[temp];
    }
    return temp;
}
int main() {
    vector<edge> edges;
    int n, edges1,questions;
    cin >> n >> edges1 >> questions;
    for(int i = 0; i <= n; i ++){
        father[i] =i;
        weight[i] = 1;
    }
    int max1 = 0;
    for(int i = 0; i < edges1; i++){
        int a ,b ,c;
        cin >> a >> b >> c;
        edge temp = {a,b,c};
        edges.push_back(temp);
        max1 = max(c,max1);

    }
    sort(edges.begin(),edges.end());
    int count = 0;
    for(int i = 0; i <= max1; i++){
        while(edges[count].weight ==i and count < edges.size()){
            int temp = edges[count].start;
            int temp1= edges[count].end;
            if(i > 0) length[i]=length[i-1];
            cout << temp << endl;
            for(int i = 0; i <= n; i++){
                cout << father[i];
            }
            int a = find(temp);
            int b = find(temp1);
            length[i] += weight[b]*weight[a];
            weight[b] +=weight[a];
            father[a] = b;
            count++;
        }
    }
    
    for(int i = 0; i < questions; i++){
        int query;
        cin >> query;
        cout << length[query] << endl;
    }
    return 0;
}