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
    lli ans = 4;
    set<lli> ts;
    fore(i,0,10){
        lli num;
        cin >> num;
        if(!ts.count(num)){
            ans--;
            ts.insert(num);
        }
    }
    cout << ans << endl;
    return 0;
}