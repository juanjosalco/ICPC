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
    lli n;
    cin >> n;
    vi a(2*n);
    lli sum = 0;
    set<lli> st;
    fore(i,0,n){
        lli num;
        cin >> num;
        a[i] = num;
        a[i+n] = a[i];
        sum += a[i];
    }
    if(sum % 3){
        cout << 0 << endl;
        return 0;
    }
    sum /= 3;
    vi pref(2*n+1, 0);
    fore(i,1,2*n+1){
        pref[i] = a[i-1]+pref[i-1];
    }
    lli ans = 0;
    fore(i,1,n+1){
       lli nxt1 = lower_bound(pref.begin(), pref.end(), (pref[i]+sum)) - pref.begin();
       if(pref[nxt1] == pref[i]+sum){
            lli nxt2 = lower_bound(pref.begin(), pref.end(), (pref[i]+sum+sum)) - pref.begin();
            if(pref[nxt2] == (pref[i]+sum+sum)){
                lli nxt3 = lower_bound(pref.begin(), pref.end(), (pref[i]+sum+sum+sum)) - pref.begin();
                if(pref[nxt3] == (pref[i]+sum+sum+sum)){
                    ans++;
                }
            }
        }
    }
    cout << ans/3 << endl;
}