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

int main(){ _
    lli n, k;
    cin >> n >> k;
    vi l(n);
    vi r(n);
    fore(i,0,n){
        cin >> l[i];
    }
    fore(i,0,n){
        cin >> r[i];
    }
    sort(all(l));
    sort(all(r));

    vi ans(n+1);
    ans[0] = l[0]+r[0];
    fore(i,1,n){
        ans[i] = l[i]+r[i]+ans[i-1];
    }
    lli tot = upper_bound(all(ans), k) - ans.begin();
    if(tot >= n) cout << n << endl;
    else cout << tot << endl;
    return 0;
}