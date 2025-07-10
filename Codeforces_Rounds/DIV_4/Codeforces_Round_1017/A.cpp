#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef pair<lli,lli> ii;

#define endl '\n'
#define f first
#define s second
#define all(s) begin(s), end(s)
#define pb push_back
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ld EPS = 1e-9;
const lli INF = 1e9;
const lli MOD = 1e9+7;

// g++ -std=c++17 A.cpp && ./a.out <in.txt> out.txt
// g++ -std=c++17 A.cpp && ./a.exe <in.txt> out.txt

int main(){ _
    lli t;
    cin >> t;
    while(t--){
        string ans;
        fore(i,0,3){
            string x;
            cin >> x;
            ans+= x[0];
        }
        cout << ans << endl;
    }
    return 0;
}