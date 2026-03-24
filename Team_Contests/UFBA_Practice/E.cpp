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

const lli INF = 1e9;
const lli MOD = 1e9+7;
const ld EPS = 1e-9;

bool sol(lli n, string& a){
    if (n < 2)
        return true;

    vector<lli> p(n);
    lli x = 0;
    fore(i, 0, n)
        p[i] = (x^=a[i] == '1');

    x = a[n-1]=='1';
    if (x != p[n-2])
        return false;
    
    for(lli i = n-2; i > 0; i--){
        if ((p[i-1] == x) == (a[i]=='1'))
            return false;
        x ^= (a[i]=='1');   
    }
    return (a[0] == '1') == x;
}

int main(){ _
    string a;
    cin >> a;
    lli n = a.size();

    cout << (sol(a.size(), a) ? "YES" : "NO");
    return 0;
}