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
 
lli const MOD = 998244353;
 
int main(){ _
    string st;
    cin >> st;
    lli ans = 0;
    char prev = 'R';
    lli maxi = 0;
    fore(i,0,st.size()){
        if(st[i] != prev){
            prev = st[i];
            maxi = 0;
        }
        maxi++;
        ans = max(ans, maxi);
    }
    cout << ans << endl;
    return 0;
}