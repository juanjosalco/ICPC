#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef pair<int,int> ii;

#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(s) begin(s), end(s)
#define fore(i,a,b) for(int i = (a); i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){ _
    int n, k;
    cin >> n >> k;

    vector<string> grid(n);
    fore(i,0,n){
        cin >> grid[i];
    }

    vector<vi> dist(n, vi(n, -1));
    vector<set<lli>> rowsUn(n), colsUn(n);

    fore(r,0,n){
        fore(c,0,n){
            if(grid[r][c] == '.'){
                rowsUn[r].insert(c);
                colsUn[c].insert(r);
            }
        }
    }

    dist[0][0] = 0;

    rowsUn[0].erase(0);
    colsUn[0].erase(0);

    queue<ii> q;
    q.push({0,0});

    while(!q.empty()){
        auto [r,c] = q.front(); 
        q.pop();
        lli d = dist[r][c];
        
        auto it = rowsUn[r].upper_bound(c);

        while(it != rowsUn[r].end()){
            lli cc = *it;
            if(cc > c + k) break;
        
            dist[r][cc] = d + 1;
            q.push({r,cc});

            auto visited = it;
            ++it;

            rowsUn[r].erase(visited);
            colsUn[cc].erase(r);
        }
        
        
        it = colsUn[c].upper_bound(r);

        while(it != colsUn[c].end()){
            lli rr = *it;
            if(rr > r + k) break; 

            dist[rr][c] = d + 1;
            q.push({rr,c});

            auto visited = it;
            ++it;

            colsUn[c].erase(visited);
            rowsUn[rr].erase(c);
        }
        
    }

    cout << dist[n-1][n-1] << endl;
    return 0;
}
