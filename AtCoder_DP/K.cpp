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

vector<vector<vi>> dp(101,vector<vi>(1e5+7, vi(2, -1)));
vector<vector<vector<bool>>> vis(101,vector<vector<bool>>(1e5+7, vector<bool>(2, false)));
vi a(100);

lli n, k;

lli fun(lli x, lli st, lli pl){
    if(x < 0 || st <= 0) return pl == 0 ? 1 : 0;
    if(vis[x][st][pl]) return dp[x][st][pl];

    if(pl == 0){
        fun(x-1,st-a[x], 1);
    }
    if(pl == 1){
        fun(x-1,st-a[x], 0);
    }

    vis[x][st][pl] = true;


    return dp[x][st][pl];
    
}

int main(){ _
    cin >> n >> k;
    fore(i,0,n){
        cin >> a[i];
    }
    cout << fun(n-1, k, 0) << endl;
    // if(fun(n-1, k, 1) == 1){
    //     cout << "First" << endl;
    // }else{
    //     cout << "Second" << endl;
    // }
    return 0;
}