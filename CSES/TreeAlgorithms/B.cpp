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
vector<bool> vis(1e6, false);
vector<bool> vis2(1e6, false);
lli lastNode = -1;

lli bfs(lli x){
    queue<lli> q;
    q.push(x);
    vis[x]=true;
    lli lvl = 0;
    while(!q.empty()){
        lli sz = q.size();
        fore(i,0,sz){
            lli fr = q.front();
            lastNode = fr;
            q.pop();
            for(auto ch : g[fr]){
                if(!vis[ch]){
                    q.push(ch);
                    vis[ch] = true;
                }
            }
        }
        lvl++;
    }
    return lvl;
}

int main(){ _
    lli n;
    cin >> n;

    g.assign(n+1, vi());

    fore(i,0,n-1){
        lli u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    bfs(1);
    vis.assign(1e6, false);
    cout << bfs(lastNode)-1 << endl;

    return 0;
}
