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
    lli n, m;
    cin >> n >> m;
    vi a(n, 0);
    if(n == m) cout << "*" << endl;
    fore(i,0,m){
        lli num;
        cin >> num;
        num--;
        a[num] = 1;
    }
    fore(i,0,n){
        if(!a[i]) cout << i+1 << " ";
    }
    return 0;
}