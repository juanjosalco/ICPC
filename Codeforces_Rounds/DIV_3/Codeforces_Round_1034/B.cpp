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
        lli n, j, k;
        cin >> n >> j >> k;
        vi a(n);
        lli maxi = LLONG_MIN;
        fore(i,0,n){
            cin >> a[i];
            maxi = max(maxi, a[i]);
        }
        lli sl = a[j-1];
        if(sl == maxi){
            cout << "YES" << endl;
        }else{
            if(k >= 2){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl; 
            }
        }
    }
    return 0;
}