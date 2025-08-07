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
#define fore(i,a,b) for(lli i = a; i <(b);i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

lli const MOD = 1e9+7;
lli const INF = 1e9;
ld const EPS = 1e-9;

lli mcd(lli a, lli b){return b ? mcd(b, a%b): a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0:a*b/mcd(a,b);}

int main(){ _
    lli t;
    cin >> t;
    while(t--){
        lli l1,b1,l2,b2,l3,b3;
        cin >>l1>>b1>>l2>>b2>>l3>>b3;
        bool ok = 0;
        if (l1 == l2 && l2 == l3 && b1+b2+b3 == l1) ok = 1;
        if (b1 == b2 && b2 == b3 && l1+l2+l3 == b1) ok = 1;
        if (l2 == l3 && b2+b3 == b1 && l1+l2 == b1) ok = 1;
        if (b2 == b3 && l2+l3 == l1 && b1+b2 == l1) ok = 1;
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}