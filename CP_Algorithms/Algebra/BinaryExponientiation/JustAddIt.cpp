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

const lli MOD = 1e7+7;

lli k;

lli binpow(lli a, lli b){
    a %= MOD;
    lli res = 1;
    while(b > 0){
        if(b & 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main(){ _
    while(true){
        lli n;
        cin >> n >> k;
        if(n == 0 && k == 0) return 0;
        lli ans = 2 * binpow(n-1,k) % MOD;
        ans = ans + binpow(n,k) % MOD;
        ans = ans + (2 * binpow(n-1,n-1) % MOD) % MOD;
        ans = ans + binpow(n,n) % MOD;
        cout << ans % MOD << endl;
    }
    return 0;
}