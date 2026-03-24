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
vi h(1e5+7, 0);

lli k;

lli fun(lli x){
    if(x <= 0) return 0;
    if(vis[x]) return dp[x];
    lli mini = LLONG_MAX;
    for(lli i = k; i >= 1; i--){
        if(x-i >= 0){
            mini = min(fun(x-i)+abs(h[x]-h[x-i]), mini);
        }
        dp[x]= mini;
        vis[x] = true;
    }
    return dp[x];
}

int main(){ _
    lli n;
    cin >> n >> k;
    fore(i,0,n){
        cin >> h[i];
    }
    cout << fun(n-1) << endl;
    return 0;
}