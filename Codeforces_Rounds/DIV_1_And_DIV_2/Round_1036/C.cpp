#include <bits/stdc++.h> 

using namespace std;

typedef long long int  lli;
typedef long double    ld;
typedef vector<lli>    vi;
typedef pair<lli,lli>  ii;

#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(s) begin(s), end(s)
#define fore(i,a,b) for(lli i = (a); i < (b); ++i)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const lli MOD = 1e9;
const lli INF = 1e9;
const ld  EPS = 1e-9;

int main(){ _
    lli t;
    cin >> t;
    while (t--){
        lli n, x;                
        cin >> n >> x;
        --x;                

        string s;                 
        cin >> s;

        bool WL = false, WR = false;
        fore(i,0,x){
            if (s[i] == '#') WL = true;
        }
        fore(i,x+1,n){
            if (s[i] == '#') WR = true;
        }

        lli dL =  x;
        lli dR =  n - 1 - x;

        auto cost = [](bool hasWall, lli dist){
            return hasWall ? dist + 1 : 1;
        };
        lli CL = cost(WL, dL);
        lli CR = cost(WR, dR);


        lli ans;
        if (!WL && !WR) {                 
            ans = 1;
        } else if (!WL) {              
            ans = min(dL + 1, CR);       
        } else if (!WR) {               
            ans = min(CL, dR + 1);        
        } else {                        
            ans = min(CL, CR);            
        }

        cout << ans << endl;
    }
    return 0;
}
