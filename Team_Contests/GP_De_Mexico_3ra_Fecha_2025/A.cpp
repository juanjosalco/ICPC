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
const lli INF = 1e9;
const ld EPS = 1e-9;

lli mcd(lli a, lli b){return b ? mcd(b, a%b): a;}
lli mcm(lli a, lli b){return (!b || !a) ? 0 : a * b / mcd(a,b);}

int main(){ _
    lli n;
    cin >> n;
    lli sum = 0;
    fore(i,0,n){
        lli num;
        cin >> num;
        sum += num;
    }
    lli ans = 0;
    while(n){
        if(sum % n == 0){
            cout << ans << endl;
            break;
        }
        ans++;
        n--;
    }
    return 0;
}