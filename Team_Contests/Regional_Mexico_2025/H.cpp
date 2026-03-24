#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef long double ld;
typedef pair<lli,lli> ii;

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define all(s) begin(s), end(s)
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){ _
    lli n;
    cin >> n;
    lli maxi = 0;
    lli ans = 0;
    fore(i,0,n){
        lli num;
        cin >> num;
        if(num > maxi){
            ans++;
            maxi = num;
        }
    }
    cout << ans << endl;
    return 0;
}
