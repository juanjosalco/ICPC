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

vi fib(50);
const lli MOD = 1e18;

void fill(){
    fib[0] = 1;
    fib[1] = 1;
    fore(i,2,50){
        fib[i] = fib[i-1] + fib[i-2] % MOD;
    }
}

int main(){ _
    fill();
    lli t;
    cin >> t;
    while(t--){
        lli x, k;
        cin >> x >> k;
        fore(i,1,50){
            if(x*fib[i] >= k){
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}