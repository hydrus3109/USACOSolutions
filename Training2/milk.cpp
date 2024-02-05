/*/*
ID: Aidan Gao[weiya.x1]
LANG: C++
TASK: milk
*/

#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;


int main() {
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    int total;
    int farmers;
    fin >> total >> farmers;
    std::deque<pair<int,int>> selling;
    int total_cost = 0;
    for (int i = 0; i < farmers; ++i)
    {
        int a,b;
        fin >> a >> b;
        selling.push_back(make_pair(a,b));
    }
    sort(selling.begin(), selling.end());
    int temp = total;
    while(temp > 0){
        pair<int,int> first1 = selling.front(); 
        if(first1.second >= temp){
            total_cost += temp*first1.first;
            temp = 0;
        }
        if(first1.second < temp){
            total_cost += first1.second*first1.first;
            temp -= first1.second;
            selling.pop_front();
        }
    }
    fout << total_cost << endl;
    return 0;
}