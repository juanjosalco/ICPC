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
    lli gau = (n*(n+1))/2;
    if(gau % 2 != 0){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        lli cnt = 0;
        lli sum = 0;
        lli i = n;
        vi vis(1e6);
        while(sum < gau/2){
            if(sum+i <= gau/2){
                vis[i] = 1;
                cnt++;
                sum += i;
            }
            i--;
        }
        cout << cnt << endl;
        fore(j,1,n+1){
            if(vis[j]){
                cout << j << " ";
            }
        }
        cout << endl;
        cout << n-cnt << endl;
        fore(j,1,n+1){
            if(!vis[j]){
                cout << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}