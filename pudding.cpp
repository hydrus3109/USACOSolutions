#include <iostream>
#include <queue>
using namespace std;
#define ROW 5
#define COL 2
 
struct pudding{
    int comparison;
    int week;
    int price;
};
 
// this is an structure which implements the
// operator overloading
struct CompareHeight {
    bool operator()(pudding const& s1, pudding const& s2)
    {
        return s1.comparison > s2.comparison;
    }
};
 
int main()
{
    priority_queue<pudding, vector<pudding>, CompareHeight> Q;
    int N, S, T;
    cin >> N >> S >> T;
    int ticker = 0;
    int sum = 0;
    for(int i = 0; i < N; i++ ){
        int price, needed;
        cin >> price >> needed;
        int comp = price - ticker;
        Q.push({comp, i+1, price});
        bool found = false;
        pudding temp;
        while(found == false){
            temp = Q.top();
            if(i - temp.week <= T){
                found = true;
            }
        }
        sum += ((i+1-temp.week)*needed*S + temp.price*needed);
        ticker += S;
        cout <<  sum <<endl;

    }

    cout << sum << endl;
    return 0;
}