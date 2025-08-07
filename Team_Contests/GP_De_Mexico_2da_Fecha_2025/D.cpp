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

vector<vi> g;

struct DSU{
  vi pr, rank;
  DSU(lli n): pr(n), rank(n, 1){ 
    iota(all(pr), 0);
  }
  lli find(lli u){ 
    return pr[u] == u ? u: pr[u] = find(pr[u]);
  }
  void unite(lli u, lli v){ 
    u = find(u), v = find(v);
    if(u != v){
      if(rank[u] < rank[v]) swap(u, v);
      rank[u] += rank[v];
      pr[v] = u;
    }
  }
  lli size(lli x){return rank[find(x)];}
};

int main() { _
    lli n, m;
    cin >> n >> m;
    vector<ii> po;
    po.reserve(n+1);
    fore(i,1,n+1){
        lli num;
        cin >> num;
        po.pb({num, i});
    }
    sort(all(po));
    g.assign(n+1, {});
    fore(i,0,m){
        lli u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    DSU dsu(n+1);
    vi ans(n+1);
    vi active(n+1, 0);

    for(size_t i = 0; i < po.size();){
        lli en = po[i].f;
        size_t j = i;
        while(j < po.size() && en == po[j].f){
            lli v = po[j].s;
            active[v] = 1;
            j++;
        }
        for(size_t k = i; k < j; k++){
            lli v = po[k].s;
            for(auto x : g[v]){
                if(active[x]){
                    dsu.unite(x,v);
                }
            }
        }
        for(size_t k = i; k < j; k++){
            lli v = po[k].s;
            ans[v] = dsu.size(v);
        }
        i = j;
    }
    fore(i,1,ans.size()){
        cout << ans[i] << endl;
    }
    return 0;
}