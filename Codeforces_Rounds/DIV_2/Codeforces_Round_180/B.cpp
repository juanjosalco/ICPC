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
const lli INF = 1e9;
const ld EPS = 1e-9;

int main(){ _
    lli t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        vector<lli> a(n);
        for (lli i = 0; i < n; ++i) cin >> a[i];

        bool beautiful = false;
        for (lli i = 0; i < n - 1; ++i) {
            if (abs(a[i] - a[i + 1]) <= 1) {
                beautiful = true;
                break;
            }
        }

        vi b = a;
        vi c = a;
        sort(all(c), greater<lli>());
        sort(all(b));
        if (beautiful) {
            cout << 0 << '\n';
        } else if (n == 2 || a == b || a == c) {
            cout << -1 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
    return 0;
}