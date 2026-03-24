#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef long double ld;
typedef pair<lli,lli> ii;

#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(s) begin(s), end(s)
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<vi> dp(1e5 + 5, vi(632, 0));
vector<vector<bool>> vis(1e5 + 5, vector<bool>(632, false));
vi a(1e5 + 5);
vi pref(1e5+5, 0);

lli n, g;

lli fun(lli pos, lli sz){
    if(pos > n || pos+sz > n) return 0;
    if(vis[pos][sz]) return dp[pos][sz];

    lli res = pref[pos+sz]-pref[pos-1];

    dp[pos][sz] = max(fun(pos+sz+1, sz+1)+(g-res), fun(pos+1, sz));
    vis[pos][sz] = true;

    return dp[pos][sz];
}

int main(){ _
    cin >> n >> g;
    fore(i,0,n){
        cin >> a[i];
    }
    fore(i,1,n+1){
       pref[i]=pref[i-1]+a[i-1];
    }

    lli ans = fun(1, 0);
    cout << ans << endl;
    return 0;
}