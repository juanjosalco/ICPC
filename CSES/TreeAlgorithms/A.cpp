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

lli mcd(lli a, lli b){return b ? mcd(b, a%b) : a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a * b / mcd(a,b);}

vector<vi> g;
vi ans;

lli dfs(lli x){
    for(auto ch : g[x]){
        ans[x] += (dfs(ch)+1);
    }
    return ans[x];
}

int main(){ _
    lli n;
    cin >> n;

    g.assign(n+1, vi());
    ans.assign(n+1, 0);

    fore(i,2,n+1){
        lli u;
        cin >> u;
        g[u].pb(i);
    }

    dfs(1);

    fore(i,1,n+1){
        cout << ans[i] << " ";
    }
    return 0;
}
