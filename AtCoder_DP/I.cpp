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

vector<vector<ld>> dp(3000,vector<ld>(3000,1));
vector<vector<bool>> vis(3000, vector<bool>(3000,false));
vector<ld> H(3000);
vector<ld> T(3000);


lli n;
lli mid;

string fun(lli x, lli ts){
    if(x >= n) return ;
    if(vis[x][ts]) return dp[x][ts];

    ld takeH = fun(x+1, ts)*H[x];
    ld takeT = fun(x+1, ts+1)*T[x];

    cout << takeH << " " << takeT << endl;
    
    vis[x][ts] = true;
    return dp[x][ts];
}

int main(){ _
    cin >> n;
    fore(i,0,n){
        cin >> H[i];
    }
    fore(i,0,n){
        T[i] = 1-H[i];
    }
    mid = n/2+1;
    cout << fixed << setprecision(10) << fun(0, 0) << endl;
    return 0;
}