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

const lli INF = 1e9;

set<lli> trialDiv(lli n){
    set<lli> fact;
    for(lli d = 2; d*d <= n; d++){
        while(n % d == 0){
            fact.insert(d);
            n/=d;
        }
    }
    if(n > 1){
        fact.insert(n);
    }
    return fact;
}

int main(){ _
    lli n;
    cin >> n;
    set<lli> ans = trialDiv(n);
    lli sz = ans.size();
    cout << pow(2,sz)-sz-1 << endl;
    return 0;
}