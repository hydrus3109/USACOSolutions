#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;

// Driver Code
int main()
{
    int tot = 0;
    ifstream fin ("input.txt");
    string str;
    while(getline(fin,str)){
        cout << str << endl;
        int first,last;
        for(int i = 0; i < str.length(); i++){
            if(isdigit(str[i])){
                first = int(str[i]-'0');
                cout << first << " ";
                break;
            }
        }
        for(int i = str.length()-1; i >= 0; i--){
            if(isdigit(str[i])){
                last = int(str[i]-'0');
                break;
            }
        }
        tot +=  first*10;
        tot += last;
    }
    cout << tot;
    return 0;
}
