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

struct DSU {
    vi p, sz;
    vector<map<lli,lli>> mp;

    DSU(lli n): p(n), sz(n,1){
        iota(all(p), 0);
        mp = vector<map<lli,lli>>(n+1);
    }

    lli getParent(lli x){return x == p[x] ? x : p[x] = getParent(p[x]);}

    void join(lli x, lli y){
        x = getParent(x), y = getParent(y);
        if(x != y){
            if(sz[x] < sz[y]) swap(x,y);

            for(auto i : mp[y]){
                mp[x][i.f] += i.s;
            }

            sz[x]+= sz[y];
            p[y] = x;
        }
    }

    lli query(lli x, lli col){
        x = getParent(x);
        return mp[x][col];
    }
};

const lli MAXN = 1e5+10;
vector<vi> adj(MAXN);
DSU dsu(1);
vector<vector<ii>> nq(MAXN);
vi ans(MAXN);

void dfs(lli u, lli p){
    for(auto x : adj[u]){
        if(x != p){
            dfs(x, u);
            dsu.join(x, u);
        }
    }
    for(auto x : nq[u]){
        ans[x.s] = dsu.query(u, x.f);
    }
}


int main(){ _
    lli n, m;
    cin >> n >> m;

    dsu = DSU(n+1);

    fore(i,1,n+1){
        lli col;
        cin >> col;
        dsu.mp[i][col]++;
    }

    fore(i,0,n-1){
        lli u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    fore(i,0,m){
        lli x, k;
        cin >> x >> k;
        nq[x].pb({k, i});
    }

    dfs(1,1);
    fore(i,0,m){
        cout << ans[i] << endl;
    }
    return 0;
}