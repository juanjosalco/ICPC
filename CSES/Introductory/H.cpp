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
    fore(i,1,n+1){
        if(i == 1){
            cout << 0 << endl;
        }
        else if(i == 2){
            cout << 6 << endl;
        }
        else if(i == 3){
            cout << 28 << endl;
        }
        else if(i == 4){
            cout << 96 << endl;
        }else{
            lli gau = ((i*i)*((i*i)+1))/2;
            cout << gau - ((((5*2)+(4*(i-4)))*(i-2))+(4+(2*(i-4))))-(i*i) << endl;
        }
    }
    return 0;
}