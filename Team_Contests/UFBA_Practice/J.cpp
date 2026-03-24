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

vi pows(32);

void prec(){
    pows[0] = 1;
    fore(i,1,32){
        pows[i] = pows[i-1]*2LL;
    }
}

lli nxtPow(lli x){
    lli nxtIdx = upper_bound(pows.begin(), pows.end(), x) - pows.begin();
    if(pows[nxtIdx] == x) nxtIdx = upper_bound(pows.begin(), pows.end(), x+1) - pows.begin();
    return pows[nxtIdx];
}

vi bChain(lli x){
    vi chain;
    chain.pb(x);
    while(true){
        if(x == 0) break;
        lli p = nxtPow(x);
        lli y = (p - 1LL) - x;
    }
    return chain;
}

int main(){ _
    prec();
    lli n;
    cin >> n;
    vi a(n);
    fore(i,0,n){
        cin >> a[i];
    }
    vector<vi> chains(n);
    fore(i,0,n){
        chains[i] = bChain(a[i]);
    }
    cout << nxtPow(0) << endl;
    return 0;
}