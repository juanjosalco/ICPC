#include <bits/stdc++.h> 

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef pair<lli,lli> ii;

#define endl "\n"
#define f first
#define s second
#define all(s) begin(s),end(s);
#define pb push_back
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

lli mcd(lli a, lli b){return b ? mcd(b, a%b) : a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a * b / mcd(a,b);}

const lli INF = 1e9;
const lli MOD = 1e9+7;
const ld EPS = 1e-9;

ld n, k;
vector<ld> a;

bool isOk(ld x){
    ld ans = 0;
    fore(i,0,n){
        ans += floor(a[i]/x);
    }
    return ans >= k;
}

int main(){ _
    cin >> n >> k;
    a.resize(n);
    fore(i,0,n){
        cin >> a[i];
    }
    ld l = 0;
    ld r = 1;
    while(isOk(r)){
        r*=2;
    }
    fore(i,0,100){
        ld mid = (l+r)/2;
        if(isOk(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << fixed << setprecision(12) << l << endl;
    return 0;
}