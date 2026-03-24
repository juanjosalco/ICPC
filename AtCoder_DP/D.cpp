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

vector<vi> dp(101, vi(1e5+7, 0));
vector<vector<bool>> vis(101, vector<bool>(1e5+7, false));
vector<ii> a(101);

lli N, W;

lli fun(lli n, lli w){
    if(n < 0 || w > W) return 0;
    if(vis[n][w]) return dp[n][w];
    if(w+a[n].f <= W){
        dp[n][w] = max(fun(n-1, w+a[n].f)+a[n].s, fun(n-1, w));
    }else{
        dp[n][w] = fun(n-1, w);
    }
    vis[n][w] = true;
    return dp[n][w];
}

int main(){ _
    cin >> N >> W;
    fore(i,0,N){
        lli u, v;
        cin >> u >> v;
        a[i].f = u; a[i].s = v;
    }
    cout << fun(N-1, 0) << endl;
    return 0;
}