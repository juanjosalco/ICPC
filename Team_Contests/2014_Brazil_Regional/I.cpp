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

const lli INF = 1e18;

vi dp(1900, INF);
vector<bool> vis(1900, false);
vi pos;
vi a;

lli n;
lli c, t1, t2;

lli fun(lli x){
    if(x >= 2*n) return 0;
    if(vis[x]) return dp[x];

    lli up1 = upper_bound(pos.begin(), pos.end(), pos[x]+t1)-pos.begin();
    lli up2 = upper_bound(pos.begin(), pos.end(), pos[x]+t2)-pos.begin();


    dp[x] = min(fun(up1)+t1, fun(up2)+t2);
    vis[x] = true;

    return dp[x];
}

int main(){ _
    cin >> n >> c >> t1 >> t2;
    a.resize(n);
    fore(i,0,n){
        cin >> a[i];
    }
    pos.resize(2*n, 0);
    fore(i,0,n){
        pos[i] = a[i];
    }
    fore(i,n,2*n){
        pos[i] = (c-a[n-1])+a[i-n]+a[n-1];
    }
    lli ans = LLONG_MAX;
    fore(i,0,n+1){
        ans = min(ans, fun(i));
    }
    cout << ans << endl;
    return 0;
}