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

vector<vi> dp(1e5+7, vi(3, 0));
vector<vector<bool>> vis(1e5+7, vector<bool>(3, false));
vector<vi> act(1e5+7, vi(3, 0));

lli fun(lli x, lli prev){
    if(x < 0) return 0;
    if(vis[x][prev]) return dp[x][prev];
    if(prev == 0){
        dp[x][prev] = max(fun(x-1, 1)+act[x][1], fun(x-1, 2)+act[x][2]);
    }
    else if(prev == 1){
        dp[x][prev] = max(fun(x-1, 0)+act[x][0], fun(x-1, 2)+act[x][2]);
    }
    else if(prev == 2){
        dp[x][prev] = max(fun(x-1, 1)+act[x][1], fun(x-1, 0)+act[x][0]);
    }
    vis[x][prev] = true;
    return dp[x][prev];
}

int main(){ _
    lli n;
    cin >> n;
    fore(i,0,n){
        cin >> act[i][0] >> act[i][1] >> act[i][2];
    }
    cout << max({fun(n-1, 0), fun(n-1, 1), fun(n-1, 2)}) << endl;
    return 0;
}