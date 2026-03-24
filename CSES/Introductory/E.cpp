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
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    if(n <= 3){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
 
    fore(i,1,n+1){
        if(i % 2 == 0){
            cout << i << " ";
        }
    }
    fore(i,1,n+1){
        if(i % 2 != 0){
            cout << i << " ";
        }
    }
    return 0;
}