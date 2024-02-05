#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
vector<pair<char,char>> city;
vector<pair<char,char>> state;
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string str;
        getline(cin, str);
        city.push_back(make_pair(str[0],str[1]));
        state.push_back(make_pair(str[str.length()-1],str[str.length()-2]));
        
    }
    return 0;
}
