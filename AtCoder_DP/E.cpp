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
#define fore(i,a,b) for(lli i = a; i <(b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const lli MOD = 1e9;
const lli INF = 1e9;
const ld EPS = 1e-9;

lli mcd(lli a, lli b){return b ? mcd(b, a%b): a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a*b /mcd(a,b);}

vector<vi> dp(101, vi(1e5+7, 1e9+7));
vector<vector<bool>> vis(101, vector<bool>(1e5+7, false));
vector<ii> a(101);

lli N, W;
lli sum = 0;

lli fun(lli n, lli v){
    if (v < 0) return INF;
    if (n < 0) return (v == 0 ? 0 : INF);
    if (vis[n][v]) return dp[n][v];

    vis[n][v] = true;
    dp[n][v] = min(fun(n-1, v - a[n].s) + a[n].f,  fun(n-1, v));

    return dp[n][v];
}

int main(){ _
    cin >> N >> W;
    fore(i,0,N){
        lli u, v;
        cin >> u >> v;
        a[i].f = u; a[i].s = v;
        sum += v;
    }
    lli ans = 0;
    fore(v,0,sum+1){
        if (fun(N-1, v) <= W) ans = v;
    }
    cout << ans << endl;
    return 0;
}