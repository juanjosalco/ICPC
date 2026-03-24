#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef long double ld;
typedef pair<lli,lli> ii;

#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(s) begin(s), end(s)
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const lli INF = 1e9;
const lli MOD = 1e9+7;
const ld EPS = 1e-9;

int main(){ _
    lli n;
    cin >> n;
    vi a(n+1);
    fore(i,1,n+1){
        cin >> a[i];
    }

    vi pref(n+1, 0);
    fore(i,1,n+1){
        pref[i] = pref[i-1] + a[i];
    }

    vi len;     
    vi offset; 
    {
        lli L = 3;
        lli S = 0;
        while (S < n) {  
            len.pb(L);
            offset.pb(S);
            S += L;
            L *= 3;
        }
    }

    fore(i,1,n+1) {
        lli ans = 0;
        for (size_t t = 0; t < offset.size(); ++t) {
            lli start = i + offset[t];
            if (start > n) break;  
            lli rEnd = min(n, start + len[t] - 1);
            lli blockSum = pref[rEnd] - pref[start - 1];
            if (blockSum > 0) ans += blockSum;
        }
        cout << ans << endl;
    }
    return 0;
}