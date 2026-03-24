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

const lli INF = 1e9;

int main(){ _
    lli n, k;
    cin >> n >> k;
    vi a(n);
    fore(i,0,n){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<lli>());
    lli last = a[k-1];
    lli ans = 0;
    fore(i,k-1,n){
        if(a[i] == last) ans++;
    }
    cout << ans + k-1 << endl;
    return 0;
}