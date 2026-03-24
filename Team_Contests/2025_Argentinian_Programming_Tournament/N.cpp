#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef long double ld;
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
    lli minX = LLONG_MAX;
    lli minY = LLONG_MAX;

    lli maxX = LLONG_MIN;
    lli maxY = LLONG_MIN;

    fore(i,0,n){
        lli x, y;
        cin >> x >> y;
        minX = min(x, minX);
        maxX = max(x, maxX);
        minY = min(y, minY);
        maxY = max(y, maxY);
    }
    minX--;
    minY--;
    maxX++;
    maxY++;
    lli difX = maxX - minX;
    lli difY = maxY - minY;
    lli ans = difX*2 + difY*2;
    cout << ans << endl;
    return 0;
}