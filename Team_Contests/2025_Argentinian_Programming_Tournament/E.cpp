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

struct Node{
    lli val;
    vector<Node> con;
    Node(lli val = 0, vector<Node> con = {}): val(val), con(con){};
};

vector<vi> g(2e5+7);
vi vals;
lli maxi = LLONG_MIN;

void bfs(lli u){
    queue<lli> q;
    q.push(u);
    lli lvl = 0;
    while(!q.empty()){
        lli fr = q.front();
        maxi = max(maxi, vals[fr]);
        q.pop();
        for(auto x : g[fr]){
            q.push(x);
        }
    }   
}

int main(){ _
    lli n;
    cin >> n;
    vals.resize(n+1, 0);
    fore(i,1,n){
        cin >> vals[i];
    }
    fore(i,0,n-1){
        lli u, v;
        cin >> u >> v;
        g[u].pb(v);
    }
    fore(i,0,n){
        maxi = max(maxi, vals[i]);
    }
    cout << maxi << endl;
    return 0;
}