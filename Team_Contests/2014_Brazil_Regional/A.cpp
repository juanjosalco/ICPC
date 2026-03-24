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

int main(){ _
    lli a,b,c;
    cin >> a >> b >> c;
    if(a == b && b == c) cout << "*" << endl;
    else if(a == b && b != c) cout << "C" << endl;
    else if(b == c && c != a) cout << "A" << endl;
    else if(a == c && b != c) cout << "B" << endl;
    return 0;
}