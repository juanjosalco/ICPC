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

lli extended_gcd(lli a, lli b, lli& x, lli& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    lli x1, y1;
    lli d = extended_gcd(b, a%b, x1,y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool isPossible(lli a, lli b, lli c, lli& x0, lli& y0, lli& g){
    g = extended_gcd(a, b, x0, y0);
    if(c % g){
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if(a < 0) x0 = -x0;
    if(b < 0) y0 = -y0;
    return true;
}

int main(){ _
    lli a, b, c;
    cin >> a >> b >> c;
    lli x0, y0, g;
    isPossible(a,b,c,x0,y0,g);
    if((((a*x0 + b*y0) == c) || ((a*y0 + b*x0) == c)) && x0 >= 0 && y0 >= 0) cout << "Yes" << endl;
    else cout<< "No" << endl;
    return 0;
}