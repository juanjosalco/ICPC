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

lli mcd(lli a, lli b){return b ? mcd(b, a % b): a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a * b / mcd(a,b);}

const lli INF = 1e9;
const lli MOD = 1e9+7;
const ld EPS = 1e-9;

int main(){ _
    lli t;
    cin >> t;
    while(t--){
        lli n, k;
        cin >> n >> k;
        vi a(n);
        fore(i,0,n){
            cin >> a[i];
        }
        lli ans = 0;
        fore(i,0,n){
            if(a[i] == 0){
                lli cnt = 0;
                while(i < n){
                    if(a[i] == 1) break;
                    else if(cnt == k-1){
                        ans++;
                        i++;
                        break;
                    }
                    else cnt++;
                    i++;
                }
            }
        }
        cout << ans <<  endl;
    }
    return 0;
}