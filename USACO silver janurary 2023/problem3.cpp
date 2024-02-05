#include <iostream>
#include <queue>
using namespace std;

 

int main(){
    int n; 
    cin >> n;
    vector<int> intersections;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        intersections.push_back(a);
    }
    int current;
    int streak;
    string final = "";
    for(int i = 0; i < intersections.size(); i++){
        final.append("R");
    }
    int left = n-1;
    int right = n-1;
`11    while(right >= 0){
        int min1 = 100000;   
        left = right;
        if(intersections[right] == 2){
            final.append("L");
        }
        else{
           while(intersections[left] >2){
                if(intersections[left] > 2){
                min1 = min(min1, intersections[left]);
                }
                left--;
            } 
            int size = right-left;
            min1 = min1-2;
            int remainder = intersections[right] - min1;
            min1 /=2;
            for(int i = 0; i < min1; i++){
                for(int i = 0; i < size; i++){
                    final.append("L");
                }
                for(int i = 0; i < size; i++){
                    final.append("R");
                }
            }
            if(remainder > 0){
                final.append("L");
                for(int i = 0; i < remainder/2 -1; i ++){
                    final.append("R");
                    final.append("L");
                }
            }
            for(int i = right; i > left; i--){
                intersections[i] = intersections[i] - min1*2;
            }
        }
        right--;
    }
    cout << final << endl;

    return 0;
}