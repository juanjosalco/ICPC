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

const lli MOD = 1e9 + 7;

lli binPow(lli a, lli b){
    lli res = 1;
    while(b > 0){
        if(b & 1){
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}
int main(){ _
    lli n;
    cin >> n;
    lli ans = 2*4*3;
    ans = ans * binPow(4,n-3);
    lli ans2 = n-3;
    ans2 = ans2*4*3*3;
    ans2 = ans2 * binPow(4,n-4);
    ans = ans + ans2;
    cout << ans << endl;
    return 0;
}