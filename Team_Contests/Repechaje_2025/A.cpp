#include <bits/stdc++.h> 

using namespace std;

typedef long long lli;
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

const lli INF = 1e9;
const lli MOD = 1e9+7;

int main(){ _
    lli n, m;
    cin >> n >> m;
    lli ans = 0;
    vector<vi> mtx(n+1, vi(m+1, 0));
    fore(i,0,n){
        fore(j,0,m){
            cin >> mtx[i][j];
        }
    }
    fore(i,0,m){
        lli maxi = 0;
        fore(j,0,n){
            maxi = max(maxi, mtx[j][i]);
        }
        ans += maxi;
    }
    cout << ans << endl;
    return 0;
}