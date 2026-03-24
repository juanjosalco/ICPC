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
 
lli const MOD = 998244353;
 
int main(){ _
    lli n;
    cin >> n;
    lli sum = 0;
    fore(i,0,n-1){
        lli num;
        cin >> num;
        sum += num;
    }
    lli g = (n*(n+1))/2;
    cout << g-sum << endl;
    return 0;
}