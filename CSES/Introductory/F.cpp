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
    fore(i,0,n){
        lli x, y;
        cin >> y >> x;
        lli maxi = max(x,y);
        lli dou = maxi*maxi;
        lli mini = (maxi-1)*(maxi-1)+1;
        lli mid = (mini+dou)/2;
        if(maxi%2==0){
            if(x<y){
                cout << mid+abs(x-y) << endl;
            }else{
                cout << mid-abs(x-y) << endl;
            }
        }else{
            if(x<y){
                cout << mid-abs(x-y) << endl;
            }else{
                cout << mid+abs(x-y) << endl;
            }
        }
    }
    return 0;
}