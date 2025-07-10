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

const lli MOD = 1e9 + 7;
const lli INF = 1e9;
const ld EPS = 1e-9;

lli n, k;
vector<vi> g;
priority_queue<lli, vi, greater<lli>> pq;
vector<bool> vis(1e5+10, false);

void bfs(lli u){
    queue<lli> q;
    q.push(u);
    vis[u] = true;
    lli cnt = 0;
    while(!q.empty() && cnt <= k){
        lli sz = q.size();
        cnt++;
        fore(i,0,sz){
            lli fr = q.front();
            pq.push(fr);
            q.pop();
            for(auto x : g[fr]){
                if(!vis[x]){
                    q.push(x);
                    vis[x] = true;
                }
            }
        }
        
    }
}

int main(){ _
    cin >> n >> k;
    g.resize(n+10);
    fore(i,0,n-1){
        lli u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<lli> excluded;
    excluded.pb(1);
    lli i = 0;
    while(pq.size() != n){
        if(!excluded[i]){
            bfs(excluded[i]);
        }
    }
    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}