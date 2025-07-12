#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef pair<lli,lli> ii;

#define endl '\n'
#define f first
#define s second
#define all(s) begin(s), end(s)
#define pb push_back
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const lli MOD = 1e9+7;
const ld EPS = 1e-9;

lli mcd(lli a, lli b){return b ? mcd(b, a % b) : a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a * b / mcd(a,b);}

int main(){ _
    lli t;
    cin >> t;
    while(t--){
        lli n, m, q;
        cin >> n >> m >> q;
        vi a(n+1);
        fore(i,1,n+1){
            cin >> a[i];
        }
        map<lli,lli> ans;
        for(lli i = 1; i*i <= m; i++){
            if(!(m % i)){
                ans[i] = 0;
                ans[m/i] = 0;
            }
        }
        for(pair<lli,lli> p : ans){
            fore(i,1,n+1){
                ans[p.f] += (a[i] % p.f < a[i-1] % p.f);
            }
        }
        while(q--){
            lli op;
            cin >> op;
            if(op == 1){
                lli i, x;
                cin >> i >> x;
                for(pair<lli,lli> p : ans){
                    ans[p.f] += (x % p.f < a[i-1] % p.f) - (a[i] % p.f < a[i-1] % p.f);
                    if(i != n){
                        ans[p.f] += (a[i+1] % p.f < x % p.f) - (a[i+1] % p.f < a[i] % p.f);
                    }
                }
                a[i] = x;
            }else{
                    lli k;
                    cin >> k;
                    cout << (ans[mcd(k, m)] < m / mcd(k, m) ? "YES" : "NO") << '\n';
                }
        }
    }
    return 0;
}