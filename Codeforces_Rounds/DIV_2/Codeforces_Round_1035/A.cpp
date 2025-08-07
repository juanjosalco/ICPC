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
        lli a,b,x,y;
        cin >> a >> b >> x >> y;
        if(a == b) cout << 0 << endl;
        else if(a < b){
            lli tot = abs(a-b);
            lli qImp = tot/2;
            lli qPar = tot/2;
            if(tot % 2 != 0){
                if(a % 2 == 0){
                    qPar++;
                }else{
                    qImp++;
                }
            }
            lli ans = (qImp*x)+(qPar*min(x,y));
            cout << ans << endl;

        }else if(abs(a-b) == 1 && a % 2 != 0){
            cout << y << endl;
        }else{
            cout << -1 << endl;
        }

    }
    return 0;
}