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
 
lli const MOD = 1e9 + 7;
 
int main(){ _
    lli n;
    cin >> n;
    fore(i,0,n){
        lli a,b;
        cin >> a >> b;
        lli mini = min(a,b);
        if(a == 0 && b == 0) cout << "YES" << endl;
        else if(a == 0 || b == 0) cout << "NO" << endl;
        else if((a+b) % 3 == 0 && abs(a-b) <= mini){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}