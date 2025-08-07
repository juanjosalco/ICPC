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

lli mcd(lli a, lli b){return b ? mcd(b, a % b): a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a * b / mcd(a,b);}

const lli INF = 1e9;
const lli MOD = 1e9+7;
const ld EPS = 1e-9;

struct cas{
    lli l, r, o;
    cas(lli l = 0, lli r = 0, lli o = 0): l(l), r(r), o(o) {}
};

int main(){ _
    lli t;
    cin >> t;
    while(t--){
        lli n, k;
        cin >> n >> k;

        vector<cas> a(n);
        
        fore(i,0,n){
            lli li, ri, oi;
            cin >> li >> ri >> oi;
            a[i].l = li;
            a[i].r = ri;
            a[i].o = oi;
        }
        sort(a.begin(),a.end(),[](const cas& x, const cas& y){return x.l < y.l;});

        lli idx = 0;
        priority_queue<ii> pq;
        vi q;
        q.pb(k);
        lli ans = k;

        while(!q.empty()){
            lli x = q.back();
            q.pop_back();

            while(idx < n && a[idx].l <= x){
                pq.emplace(a[idx].r, a[idx].o);
                idx++;
            }
             while (!pq.empty() && pq.top().f >= x) {
                auto [r, y] = pq.top();
                pq.pop();
                q.pb(y);
                ans = max(ans, y);
            }
        }
        cout << ans << endl;
    }
    return 0;
}