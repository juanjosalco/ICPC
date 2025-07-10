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
lli n;

lli binpow(lli a, lli b){
    a%=n;
    lli res = 1;
    while(b > 0){
        if(b & 1){
            res = res * a % n;
        }
        a = a * a % n;
        b >>= 1;
    }
    return res;
}

int main(){ _
    lli t;
    cin >> t;
    while(t--){
        lli k;
        cin >> n >> k;
        lli num = binpow(n,k) % n;
        string nS = to_string(num);
        cout << nS[0]<<nS[1]<<nS[2] <<"..." <<nS[nS.size()-3]<<nS[nS.size()-2]<<nS[nS.size()-1] << endl;
    }
    return 0;
}