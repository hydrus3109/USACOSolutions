#include <cstdio>
#include <cstring> 
#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#define ll long long
using namespace std;


ll a[200001];
ll st[200001];
ll pt[200001];
ll belong[200001];
int main() {
    ll n; cin >> n;
    ll group = 1;
    ll groups = sqrt(n);
    for(ll i = 0; i < n; i ++ ){
        cin >> a[i];
        if(i%groups == 0 and group < groups and i != 0){
            group++;
        }
        belong[i] = group;
    }
    for( ll i = n-1; i >= 0; i--){
        if((i + a[i]) >= n) {st[i] = 1; pt[i]=0;}
        else if(belong[i]== belong[i+a[i]]){
            st[i]= st[i+a[i]]+1;
            pt[i]= pt[i+a[i]];
        }
        else{
            st[i]=1;
            pt[i]= i+a[i];
        }

    }
    ll m; cin >> m;
    for(ll i = 0; i < m; i++){
        ll a1; cin >> a1;
        if(a1 == 1){
            ll b;
            cin >> b;
            ll sum= 0; 
            ll final = -1;
            while(final !=0){
        //        cout << a[b] << " " << pt[b];
                sum += st[b];
                final = pt[b];
                b = final;
            }
            cout << sum << endl;
        }
        if(a1 == 2 ){
            ll b,c; cin >> b >> c;
            a[b]=c;
            /*
            if(belong[b] != belong[b+c]){
                st[b]=1;
                if(b+c >= n) pt[b]=0;
                else pt[b]= b+c;
            }
            st[b] = st[b+c]+1;
            pt[b] = pt[b+c];
            */
            bool condition= true;
            ll index = b;
            while(condition==true){
                if(belong[index] != belong[b]){
                    condition= false;
                    break;
                }
                if(belong[index+a[index]] == belong[index] ){
                    st[index]= st[index+a[index]]+1;
                    pt[index]= pt[index+a[index]];
                }
                else{
                    st[index]= 1;
                    pt[index]= index+a[index];
                }

                index--;
            }
        }
    }
    return 0;
}