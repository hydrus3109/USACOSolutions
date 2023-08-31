#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include<cstring>
using namespace std;
bool a[100001];
int c[100001];
int getSum( int index)
{
    int sum = 0; // Initialize result
  
    // index in BITree[] is 1 more than the index in arr[]
    while (index>0)
    {
    //    cout << c[index]<< " ";
      //  cout << index << " " << c[index] << endl;
        sum += c[index];
        index -= index & (-index);
    }
  //  cout << endl;
    return sum;
}
void updateBIT(int n, int index)
{
    while (index <= n)
    {
  //  cout << index << " ";
    c[index] +=1;
   // cout << c[index];
  
    index += index & (-index);
    }
  //  cout << endl;
}
  
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i ++){
        int n; cin >> n;
        vector<int> temp;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            temp.push_back(a);
        }
        int smallerright[100001];
        int largerright[100001];
        int smallerleft[100001];
        int largerleft[100001];
        int count = 0;
        memset(c, 0, sizeof(c));
        for(int i =temp.size()-1; i >= 0; i--){
            //cout << temp[i] << endl;
            //cout << temp[i];
            smallerright[count] = getSum(temp[i]);
           // cout << smallerright[count] << " " << endl;
            updateBIT( temp.size(), temp[i]);
            largerright[count] = temp.size()-1 - count -smallerright[count];
            count++;
           // cout << endl;
        }
        memset(c, 0, sizeof(c));
        for(int i =0; i < temp.size(); i++){
            smallerleft[i] = getSum( temp[i]);
            updateBIT( temp.size(), temp[i]);
            largerleft[i] = i - smallerleft[i];
        }
        int sum=0;
       // cout << endl;
        for(int i = 0; i < n; i++){
          //  cout << smallerleft[i] <<  " " << largerright[i] << endl;
         //   cout << largerleft[i] << " " << smallerright[i] << endl;
            sum += smallerleft[i]*largerright[i];
           sum+= largerleft[i]*smallerright[i];
        }

        cout << sum << endl;

        

    }
	return 0;
}