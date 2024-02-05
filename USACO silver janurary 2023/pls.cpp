#include<bits/stdc++.h>
using namespace std;
map<char, char>C;
map<char, int>ru;
set<char>S, R;
int ans, len;

void dfs(char c)
{
    if(!C.count(c) || C[c] == c)return;
    S.insert(c);
    R.insert(c);
    if(S.count(C[c]))
    {
        if(R.count(C[c]))
        {
            char s = C[c];
            len++;
            bool ok = false;
            while(true)
            {
                if(ru[s] > 1){ok = true;}
                s = C[s];
                if(s == C[c])break;
                len++;
            }
            if(!ok)ans++;
        }
    }
    else dfs(C[c]);
    R.erase(c);
}

int main()
{
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size();
        C.clear(); S.clear();R.clear(); ru.clear();
        ans = len = 0;
        for(int i = 0; i < n; i++)
        {
            if(!C.count(s1[i]))
            {
                C[s1[i]] = s2[i];
            }
            else
            {
                if(s2[i] != C[s1[i]])
                {
                    ans = -1;
                    break;
                }
            }
        }
        if(ans == -1){cout<<ans<<endl;continue;}
        int tmp = 0;
        for(auto x = C.begin(); x != C.end(); x++)
        {
            if(x->first == x->second)
            {
                tmp++;
            }
            else ans++;
            ru[x->second]++;
        }

        for(auto x : C)if(!S.count(x.first))
            dfs(x.first);

        if(len + tmp == 52 && len != 0)ans = -1;
        cout<<ans<<endl;
    }
    return 0;
}