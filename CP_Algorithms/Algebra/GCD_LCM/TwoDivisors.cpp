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

const lli MOD = 1e9;

lli mcd(lli a, lli b){return b ? mcd(b, a % b) : a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a * b / mcd(a,b);}

int main(){ _
    lli t;
    cin >> t;
    while(t--){
        lli n, m;
        cin >> n >> m;
        cout << n*m*2 << endl;
    }
    return 0;
}