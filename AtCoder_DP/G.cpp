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

vi dp(1e5+7, 0);
vector<bool> vis(1e5+7, false);

vector<vi> g(1e5);
lli n, m;

lli fun(lli u){
    if(g[u].size() == 0) return 0;
    if(vis[u]) return dp[u];
    for(auto x : g[u]){
        dp[u] = max(fun(x)+1, dp[u]);
    }
    vis[u] = true;
    return dp[u];
}

int main(){ _
    cin >> n >> m;
    fore(i,0,m){
        lli u, v;
        cin >> u >> v;
        g[u].pb(v);
    }
    lli maxi = 0;
    fore(i,0,n+1){
        if(!vis[i]){
            maxi = max(fun(i), maxi);
        }
    }
    cout << maxi << endl;
    return 0;
}