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

const lli INF = 1e9;

int main(){ _
    lli x,y,z;
    cin >> x >> y >> z;
    lli a = 2*y +4*z;
    lli b = 2*x + 2*z;
    lli c = 4*x + 2*y;
    cout << min({a,b,c}) << endl;
    return 0;
}