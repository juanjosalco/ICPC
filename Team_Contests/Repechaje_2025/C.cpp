#include <bits/stdc++.h> 

using namespace std;

typedef long long lli;
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

const lli INF = 1e9;
const lli MOD = 1e9+7;

int main(){ _
    lli n;
    cin >> n;
    vi a;
    for(lli i = n; i >= 0; i--){
        lli num;
        cin >> num;
        if(num){
            a.pb(i);
        }
    }
    lli ans = 0;
    while(a[0] != 0){
        ans++;
        lli last = a[a.size()-1];
        vi hp;
        if(last == 0){
            fore(i,0,a.size()){
                hp.pb(a[i]+1);
                if(a[i] != 0){
                    hp.pb(a[i]);
                }
            }
            map<lli,lli> mp;
            fore(i,0,hp.size()){
                mp[hp[i]]++;
            }
            vi cl;
            for(auto x : mp){
                if(x.s == 1) cl.pb(x.f); 
            }
            a = cl;
            sort(a.begin(), a.end(), greater<lli>());
       
        }else{
            fore(i,0,a.size()){
                if(a[i]-1 >= 0){
                    hp.pb(a[i]-1);
                }
            }
            a = hp;
        }
    }
    cout << ans << endl;
    return 0;
}