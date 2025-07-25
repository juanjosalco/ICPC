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
        lli n;
        cin >> n;
        vi a(n);
        lli maxi = LLONG_MIN;
        lli mini = LLONG_MAX;
        fore(i,0,n){
            cin >> a[i];
        }
        string ans = "";
        vi b(n);
        fore(i,0,n){
            if(a[i] < mini) b[i]++;
            mini = min(mini, a[i]);
        }
        lli j = n-1;
        while(j >= 0){
            if(a[j] > maxi) b[j]++;
            maxi = max(maxi, a[j]);
            j--;
        }
        fore(i,0,n){
            if(b[i] > 0) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    return 0;
}