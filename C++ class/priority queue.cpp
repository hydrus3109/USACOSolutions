#include <iostream>
#include <queue>
using namespace std;
#define ROW 5
#define COL 2
 
struct stream{
 
    int id;
    int period; 
    int time;
};
 
// this is an structure which implements the
// operator overloading
struct CompareHeight {
    bool operator()(stream const& s1, stream const& s2)
    {
        return s1.time > s2.time;
    }
};
 
int main()
{
    priority_queue<stream, vector<stream>, CompareHeight> Q;
    int inputs;
    while(true){
        string str; 
        int a,b;
        cin >> str >> a >> b;
        if(str == "#") break;
        stream temp = {a, b, b};
        Q.push(temp);  
    }
    while(inputs > 0){
        stream top = Q.top();
        Q.pop();
        cout << top.id << endl;
        top.time = top.time+top.period;
        Q.push(top);
    }

    return 0;
}