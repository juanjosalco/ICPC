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

lli mcd(lli a, lli b){return b ? mcd(b, a % b): a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a * b / mcd(a,b);}

const lli INF = 1e9;
const lli MOD = 1e9+7;
const ld EPS = 1e-9;

lli n;

bool isPossible(vi& pr, const vi& sf){
    if (n == 1) return pr[0] == sf[0];

    fore(i,1,n){
        if (pr[i-1] % pr[i] != 0) return false;
    }

    for(int i = 0; i+1 < n; i++){
        if (sf[i+1] % sf[i] != 0) return false;
    }

    if (pr[0] %  sf[0] != 0) return false;  
    if (sf.back() % pr.back() != 0) return false;

    if (mcd(pr[0], sf[1]) != sf[0]) return false;       
    if (mcd(pr[n-2], sf[n-1]) != pr[n-1]) return false;

    for (int i = 1; i+1 < n; i++){
        lli g = mcd(pr[i], sf[i]);

        lli lr  = pr[i-1] / pr[i];        
        lli rr = sf[i+1] / sf[i];      

        lli sp =  sf[i] / g;
        lli pp =  pr[i] / g;

        if (mcd(lr,  sp) != 1) return false;
        if (mcd(rr, pp) != 1) return false;
    }
    return true;
}


int main(){ _
    lli t;
    cin >> t;
    while(t--){
        cin >> n;
        vi pr(n), sf(n);
        fore(i,0,n){
            cin >> pr[i];
        }
        fore(i,0,n){
            cin >> sf[i];
        }
        if(isPossible(pr,sf)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}