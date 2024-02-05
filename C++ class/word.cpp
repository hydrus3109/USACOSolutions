#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include<set>
#include<queue>

using namespace std;
typedef pair<int,int> ipair;
vector<int> nums;
int main(){
    int n = nums.size();
    bool filled[500000] = {false};
    for(int i =0; i < nums.size(); i++){
        if(nums[i] > 0 && nums[i] < n+1)
            filled[nums[i]-1] =true;
    }
    for(int i = 0; i < n; i ++ ){
        if(filled[i] == false) return i+1;
    }
    return n+1;
}
