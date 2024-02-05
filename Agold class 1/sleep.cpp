#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int T[100001];
int getSum(int i)
{
	int c=0;
	for(++i; i > 0 ; i -= (i & -i))
		c += T[i];
	return c;
}
void set(int i,int dif)
{
	for(++i; i < 100001; i += (i & -i))
		T[i] += dif;
}

int main(){
    int size;
    cin >> size;
    vector<int> cows;
    for(int i = 0; i <size; i++){
        int a;
        cin >> a;
        cows.push_back(a);
    }
    int j = size-1;
    while(j > 0 and T[j-1] < T[j]){
        j--;
    }
    cout << j <<endl;
    for(int i = j; i < size;i++){
        set(cows[i],1);
    }
    for(int i=0;i<j;i++){
		cout << (j - 1 - i) + getSum(cows[i]);
		if(i < j - 1) cout << ' ';
		set(cows[i],1);
	}
    return 0;
}