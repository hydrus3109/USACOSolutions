#include <cstdio>
#include <cstring> 
#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<set>
#define ll long long
using namespace std;

vector<int> father;
vector<int> rangeparity;
vector<int> parity;

int find(int a){
    int temp = a;
    while(father[temp] != temp){
        temp = father[temp];
    }
    return temp;
}
int main() {
    int n;
    cin >> n;
    int queues;
    cin >> queues;
    set<int> numbers;
    vector<pair<int,int>> requests;
    for(int i = 0; i < queues;i++){
        int a,b;
        cin >> a >> b;
        string str; 
        cin >> str;
        if(str == "even") parity.push_back(0);
        else parity.push_back(1);
        requests.push_back({a,b});
        numbers.insert(a);
        numbers.insert(b);
    }
    vector<pair<int,int>> real;
    for(int i = 0; i < queues;i++){
        int a = requests[i].first;
        int b= requests[i].second;
        auto it = numbers.find(a);
        int index1 = std::distance(numbers.begin(), it);
        auto it2 = numbers.find(b);
        int index2 = std::distance(numbers.begin(), it2);
        real.push_back({index1,index2+1});
    }
    for(int i = 0; i <numbers.size();i++){
        father.push_back(i);
        rangeparity.push_back(-1);
    }
    for(int i = 0; i < queues; i++){
        int a = real[i].first;
        int b= real[i].second;
        int da = find(a);
        int db = find(b);
        father[db]=da;
        if(rangeparity[da] == -1 and rangeparity[db] == -1){
            rangeparity[da] = parity[i];
        }
        else if(rangeparity[db] == -1){
            int temp = parity[i];
            if(temp == 1 and rangeparity[da] == 0) {rangeparity[da] = 1;}
            else if(temp == 1 and rangeparity[da] == 1) rangeparity[da]=0;
        }
        else if(rangeparity[da]!= -1 and rangeparity[db]!=-1){
            if(parity[i] != rangeparity[da]){
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << queues << endl;
    return 0;
}