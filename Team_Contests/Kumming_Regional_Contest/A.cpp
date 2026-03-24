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
#define fore(i,a,b) for(lli i = a; i < b; i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<vi> diag_matrix(lli n, lli m){
    vector<vi> a(n, vi(m));
    lli val = 1;
    for(lli st = 0; st <= n + m - 2; ++st){
        lli i0 = max(0ll, st - (m - 1));          
        lli i1 = min(n - 1, st);
        for(lli i = i0; i <= i1; ++i){
            lli j = st - i;
            a[i][j] = val++;
        }
    }
    return a;
}

int main(){ _
    set<lli> x;
}