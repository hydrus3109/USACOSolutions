#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    long long int usb,pc2,both;
    cin >> usb >> pc2 >> both;
    int num;
    cin >> num;
    vector<pair<long long int,long long int>> costs;
    for(int i = 0; i < num;i++){
        long long int a;
        string b;
        cin >> a >> b;
        if(b == "USB") costs.push_back({a,1});
        else costs.push_back({a,2});
    }
    sort(costs.begin(),costs.end());
    long long int total = 0, computers = 0;
    for(int i = 0; i < num; i++){
        if((usb+pc2+both) == 0) break;
        pair<long long int,long long int> current = costs[i];
        if(current.second == 1){
            if(usb > 0){
                usb--;
                total += current.first;
                computers++;
            }
            else if(both>0){
                both--;
                total+= current.first;
                computers++;
            }
        }
        if(current.second == 2){
            if(pc2 > 0){
                pc2--;
                total += current.first;
                computers++;
            }
            else if(both>0){
                both--;
                total+= current.first;
                computers++;
            }
        }
    }
    cout << computers << " " << total;
    return 0;
}
