#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef pair<lli,lli> ii;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(s) begin(s), end(s)
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
lli const MOD = 1e9 + 7;
 
int main(){ _
    string st;
    cin >> st;
    map<char,lli> mp;
    lli fl = 0;
    fore(i,0,st.size()){
        mp[st[i]]++;
    }
    for(auto x : mp){
        if(x.s % 2 != 0) fl++;
    }
    string ans = "";
    if(fl > 1){
        cout << "NO SOLUTION" << endl;
    }else if(fl == 1){
        char miss;
        for(auto x : mp){
            if(x.s % 2 == 0){
                fore(j,0,x.s/2){
                    ans+=x.f;
                }
            }else{
                miss = x.f;
            }
        }
        string com = ans;
        reverse(all(ans));
        fore(j,0,mp[miss]){
            com += miss;
        }
        com += ans;
        cout << com << endl;
    }else{
        for(auto x : mp){
            fore(j,0,x.s/2){
                ans+=x.f;
            }
        }
        string com = ans;
        reverse(all(ans));
        com += ans;
        cout << com << endl;
    }
    return 0;
}