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
const lli INF = 1e9;
const ld EPS = 1e-9;

lli mcd(lli a, lli b){return b ? mcd(b, a%b): a;}
lli mcm(lli a, lli b){return (!b || !a) ? 0 : a * b / mcd(a,b);}


ld h1, h2, b;

ld binPow(ld a, lli b) {
    ld res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

bool isPos(lli x){
    return h1*(binPow(((b-1)/b),x)) <= h2;
}

int main(){ _
    lli t;
    cin >> t;
    while(t--){
        cin >> h1 >> h2 >> b;
        lli l = 0;
        lli r = 1;
        while(!isPos(r)){
            r*=2;
        }
        while(l+1 < r){
            lli mid = (l+r)/2;
            if(isPos(mid)){
                r = mid;
            }else{
                l = mid;
            }
        }
        cout << r << endl;
    }
    return 0;
}