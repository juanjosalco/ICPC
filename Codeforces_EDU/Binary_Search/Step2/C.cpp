#include <bits/stdc++.h> 

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef pair<lli,lli> ii;

#define endl "\n"
#define f first
#define s second
#define all(s) begin(s),end(s);
#define pb push_back
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

lli mcd(lli a, lli b){return b ? mcd(b, a%b) : a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a * b / mcd(a,b);}

const lli INF = 1e9;
const lli MOD = 1e9+7;
const ld EPS = 1e-9;

lli n, x, y;

bool isOk(lli u){
    lli cop = 1;
    cop += u/x;
    cop += u/y;
    return cop >= n;
}

int main(){ _
    cin >> n >> x >> y;
    lli l = 0;
    lli r = 1;
    while(!isOk(r)){
        r*=2;
    }
    while(l + 1 < r){
        lli mid = (l+r)/2;
        if(isOk(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    if(n == 1){
        cout << min(x,y) << endl;
    }else{
        cout << r+min(x,y) << endl;
    }
    return 0;
}