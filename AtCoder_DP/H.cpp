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

const lli MOD = 1e9+7;

vector<vi> dp(1001, vi(1001, 0));
vector<vector<bool>> vis(1001, vector<bool>(1001, false));

lli n, m;
vector<vector<char>> mtx(1001, vector<char>(1001));

lli fun(lli r, lli d){
    if(r >= n || d >= m) return 0;
    if(vis[r][d]) return dp[r][d];
    if(mtx[r][d] == '#') return 0;
    if(mtx[r][d] == '$') return 1;

    dp[r][d] = (dp[r][d] + fun(r+1, d)) % MOD;
    dp[r][d] = (dp[r][d] + fun(r, d+1)) % MOD;
    vis[r][d] = true;

    return dp[r][d] % MOD;
}

int main(){ _
    cin >> n >> m;
    fore(i,0,n){
        fore(j,0,m){
            cin >> mtx[i][j];
        }
    }
    mtx[n-1][m-1] = '$';
    cout << fun(0,0) << endl;
    return 0;
}