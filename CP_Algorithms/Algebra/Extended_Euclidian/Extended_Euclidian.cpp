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

const lli MOD = 1e9;

lli mcd(lli a, lli b){return b ? mcd(b, a % b) : a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a * b / mcd(a,b);}

lli extended_gcd(lli a, lli b, lli& x, lli& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    lli x1, y1;
    lli d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main(){ _
    lli a, b, c;
    cin >> a >> b >> c;
    lli x, y;
    lli g = extended_gcd(a,b,x,y);
    cout << x<< " " << " " << y << endl;
    cout << g << endl;
    return 0;
}