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

const lli MOD = 1e9+7;
const ld EPS = 1e-9;

lli mcd(lli a, lli b){return b ? mcd(b, a % b) : a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a * b / mcd(a,b);}

vector<bool> comp(1e5+5);
vi primes;

void criba(){
    for(lli i = 2; i * i <= 1e5; i++){
        if(!comp[i]){
            for(lli j = i*i; j <= 1e5; j+=i){
                comp[j]=true;
            }
        }
    }
    for(lli i = 2; i <=1e5; i++){
        if(!comp[i]){
            primes.pb(i);
        }
    }
}

int main(){ _
    criba();
    lli t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        vi p(n+1);
        for(lli i = primes.size()-1; i >= 0; i--){
            lli prime = primes[i];
            vi cycle;
            for(lli j = prime; j <= n; j += prime){
                if(!p[j]){
                    cycle.pb(j);
                }
            }
            fore(j,0,cycle.size()){
                p[cycle[j]] = cycle[(j+1) % cycle.size()];
            }
        }
        cout << 1 << " ";
        fore(i,2,n+1){
            cout << p[i] << " ";
        }
        cout << endl;
        

    }
    return 0;
}