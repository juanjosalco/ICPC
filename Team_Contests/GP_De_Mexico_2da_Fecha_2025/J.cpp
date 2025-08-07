#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef pair<lli,lli> ii;

#define endl '\n'
#define pb push_back
#define f first
#define s second
#define all(s) begin(s), end(s)
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const lli INF = 1e9;
const lli MOD = 998244353;

lli mcd(lli a, lli b){return b ? mcd(b, a%b): a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a * b / mcd(a,b);}

vi fact(1e6+10);
vi invFact(1e6+10);

lli binPowMod(lli a, lli b){
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

void preFact(){
    fact[1] = 1;
    fore(i,2,1e6+10){
        fact[i] = fact[i-1]*i % MOD;    
    }
}

void preInvFact(){
    invFact[1e6+8] = binPowMod(fact[1e6+8], MOD - 2);
    for (int i = 1e6+8; i > 0; --i){
        invFact[i - 1] = invFact[i] * i % MOD;
    }
}

int main(){
    preFact();
    preInvFact();
    lli t;
    cin >> t;
    while(t--){
        lli n, k;
        cin >> n >> k;
        n++;
        k++;
        lli ans = fact[n] * invFact[k] % MOD * invFact[n-k] % MOD;
        cout << ans << endl;
    }
    return 0;
}