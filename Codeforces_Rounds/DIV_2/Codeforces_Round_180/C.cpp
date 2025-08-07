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

const lli MOD = 1e9+7;
const lli INF = 1e9;
const ld EPS = 1e-9;

lli mcd(lli a, lli b){return b ? mcd(b, a%b):a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a * b / mcd(a,b);}

int main() {_
    lli t;                        
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        vi a(n);
        fore(i,0,n){
            cin >> a[i];
        }
        lli last = a[n-1];               
        lli ans  = 0;
        fore(k,2,n) {
            lli m = max(last, 2 * a[k]);
            lli sum = m - a[k];

            int i = 0, j = k - 1;
            while (i < j) {
                if (a[i] + a[j] > sum) {
                    ans += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
